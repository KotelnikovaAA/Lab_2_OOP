//
// Created by Anna on 23.11.2020.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "WorkFlowParser.h"
#include "WorkFlowValidator.h"

void WorkFlow::WorkFlowParser::runParser(const bool isConsoleInputStream, const bool isConsoleOutputStream,
                                         const std::string &inputFileName, const std::string &outputFileName) {
    std::ifstream sourceFile;
    sourceFile.open(sourceFileName);
    if (!sourceFile.is_open()) {
        throw std::runtime_error(
                "RunParser error: The program couldn't open source file. Please, check the file name to correct value.");
    }
    std::string currentInputLine;
    std::getline(sourceFile, currentInputLine);
    WorkFlow::WorkFlowValidator::checkStringIsInitialBorder(currentInputLine);

    while (std::getline(sourceFile, currentInputLine)) {
        if (sourceFile.eof()) {
            throw std::runtime_error("RunParser error: The source file doesn't include finite border.");
        }

        if (WorkFlow::WorkFlowValidator::checkStringIsFiniteBorder(currentInputLine)) {
            break;
        }

        std::istringstream strIStream(currentInputLine);
        tryReadCurrentString(strIStream, currentInputLine);
        auto commandId = ::WorkFlow::WorkFlowValidator::checkValueIsNumber(currentInputLine);
        tryReadCurrentString(strIStream, currentInputLine);
        WorkFlow::WorkFlowValidator::checkStringIsEqually(currentInputLine);
        tryReadCurrentString(strIStream, currentInputLine);
        auto countCommandArgs = ::WorkFlow::WorkFlowValidator::checkCommandName(currentInputLine);
        commandNamesByIdMap[commandId] = currentInputLine;

        if (countCommandArgs == 0) {
            argumentsByIdMap[commandId].clear();
        } else {
            for (size_t counter = 0; counter < countCommandArgs; counter++) {
                tryReadCurrentString(strIStream, currentInputLine);
                argumentsByIdMap[commandId].push_back(currentInputLine);
            }
        }

        if (!strIStream.eof()) {
            throw std::runtime_error(
                    "RunParser error: Some input string from source file contains invalid number of data.");
        }
    }

    if (sourceFile.eof()) {
        throw std::runtime_error(
                "RunParser error: The source file doesn't contain command order. Please, check it and try again.");
    }

    std::getline(sourceFile, currentInputLine);
    std::istringstream strIStream(currentInputLine);
    while (!strIStream.eof()) {
        strIStream >> currentInputLine;
        auto commandId = WorkFlow::WorkFlowValidator::checkValueIsNumber(currentInputLine);
        if (argumentsByIdMap.count(commandId) == 0) {
            throw std::runtime_error(
                    "RunParser error: The command order from source file contains invalid data. Please, check it and try again.");
        }
        commandOrder.push_back(commandId);
        if (strIStream.eof()) {
            break;
        }
        strIStream >> currentInputLine;
        WorkFlow::WorkFlowValidator::checkStringIsArrow(currentInputLine);

        if (strIStream.eof()) {
            throw std::runtime_error(
                    "RunParser error: The command order from source file has invalid format. Please, check it and try again.");
        }
    }

    unsigned int inFileId;
    if (isConsoleInputStream) {
        inFileId = findNextPositiveFreeCommandIndex(0);
        commandOrder.insert(commandOrder.begin(), inFileId);
        commandNamesByIdMap[inFileId] = "readfile";
        argumentsByIdMap[inFileId].push_back(inputFileName);
    }

    unsigned int outFileId;
    if (isConsoleOutputStream) {
        outFileId = findNextPositiveFreeCommandIndex(inFileId + 1);
        commandOrder.insert(commandOrder.end(), outFileId);
        commandNamesByIdMap[outFileId] = "writefile";
        argumentsByIdMap[outFileId].push_back(outputFileName);
    }

    for (const auto &item : commandOrder) {
        unsigned int firstOperationsNumberToExecute = commandOrder.front();
        unsigned int lastOperationsNumberToExecute = commandOrder.back();
        if (item == firstOperationsNumberToExecute) {
            if (commandNamesByIdMap.at(firstOperationsNumberToExecute) != "readfile") {
                throw std::runtime_error(
                        "RunParser error: The first command to execute should be 'readfile', but a different command was received.");
            }
        } else if (item == lastOperationsNumberToExecute) {
            if (commandNamesByIdMap.at(lastOperationsNumberToExecute) != "writefile") {
                throw std::runtime_error(
                        "RunParser error: The last command to execute should be 'writefile', but a different command was received.");
            }
        } else {
            if (commandNamesByIdMap.at(item) == "readfile" || commandNamesByIdMap.at(item) == "writefile") {
                throw std::runtime_error(
                        "Run Parser error: The command order contains multiple 'readfile'/'writefile' commands.");
            }
        }
    }

    while (!sourceFile.eof()) {
        throw std::runtime_error("RunParser error: The source file contains excess data.");
    }

    sourceFile.close();

}

void WorkFlow::WorkFlowParser::setSourceFileName(const std::string &newSourceFileName) {
    WorkFlowParser::sourceFileName = newSourceFileName;
}

std::map<unsigned int, std::vector<std::string>> WorkFlow::WorkFlowParser::getArgumentsByIdMap() const {
    return argumentsByIdMap;
}

std::map<unsigned int, std::string> WorkFlow::WorkFlowParser::getCommandNamesByIdMap() const {
    return commandNamesByIdMap;
}

std::vector<unsigned int> WorkFlow::WorkFlowParser::getCommandOrder() const {
    return commandOrder;
}

void WorkFlow::WorkFlowParser::tryReadCurrentString(std::istringstream &stream, std::string &string) {
    if (stream.eof()) {
        throw std::runtime_error("RunParser error: The input string doesn't contain any data.");
    }
    stream >> string;
}

unsigned int WorkFlow::WorkFlowParser::findNextPositiveFreeCommandIndex(const unsigned int leftBorder) {
    unsigned int number;
    for (number = leftBorder; number < UINT_MAX; number++) {
        if (std::find(commandOrder.begin(), commandOrder.end(), number) == commandOrder.end()) {
            break;
        }
    }
    return number;
}
