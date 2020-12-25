//
// Created by Anna on 02.12.2020.
//

#include "ArgumentsHandler.h"

void checkCorrectArgsCounter(unsigned int argumentsCount) {
    if (argumentsCount != static_cast<unsigned int>(WorkFlow::RequiredArgsNumber::WITHOUT_IN_AND_OUT_FILES) &&
        argumentsCount != static_cast<unsigned int>(WorkFlow::RequiredArgsNumber::WITH_IN_OR_OUT_FILE) &&
        argumentsCount != static_cast<unsigned int>(WorkFlow::RequiredArgsNumber::WITH_IN_AND_OUT_FILES)) {
        throw std::runtime_error(
                "ArgHandler error: The number of parameters passed is not what was expected. Check it and try again...");
    }
}

void WorkFlow::ArgumentsHandler::checkArgumentValues() {

    setSourceFileName();

    std::string commandWindowThirdInputString;
    std::string commandWindowForthInputString;
    std::string commandWindowFifthInputString;
    std::string commandWindowSixthInputString;



    switch (argumentsCounterStatus) {
        case RequiredArgsNumber::WITHOUT_IN_AND_OUT_FILES:
            break;
        case RequiredArgsNumber::WITH_IN_OR_OUT_FILE:
            commandWindowThirdInputString = argumentValues[2];
            commandWindowForthInputString = argumentValues[3];
            if (commandWindowThirdInputString == IS_INPUT_RUN_KEY) {
                isConsoleInputStream = true;
                setInputFileName(commandWindowForthInputString);
            } else if (commandWindowThirdInputString == IS_OUTPUT_RUN_KEY) {
                isConsoleOutputStream = true;
                setOutputFileName(commandWindowForthInputString);
            } else {
                throw std::runtime_error("ArgHandler error: The arguments string has invalid format.");
            }
            break;
        case RequiredArgsNumber::WITH_IN_AND_OUT_FILES:
            commandWindowThirdInputString = argumentValues[2];
            commandWindowForthInputString = argumentValues[3];
            commandWindowFifthInputString = argumentValues[4];
            commandWindowSixthInputString = argumentValues[5];

            if (commandWindowThirdInputString == IS_INPUT_RUN_KEY &&
                commandWindowFifthInputString == IS_OUTPUT_RUN_KEY) {
                isConsoleInputStream = true;
                isConsoleOutputStream = true;
                setInputFileName(commandWindowForthInputString);
                setOutputFileName(commandWindowSixthInputString);
            } else if (commandWindowThirdInputString == IS_OUTPUT_RUN_KEY &&
                       commandWindowFifthInputString == IS_INPUT_RUN_KEY) {
                isConsoleInputStream = true;
                isConsoleOutputStream = true;
                setInputFileName(commandWindowSixthInputString);
                setOutputFileName(commandWindowForthInputString);
            } else {
                throw std::runtime_error("ArgHandler error: The arguments string has invalid format.");
            }
            break;
    }


}

void WorkFlow::ArgumentsHandler::setArgumentsCount(unsigned int newArgumentsCount) {
    checkCorrectArgsCounter(newArgumentsCount);
    argumentsCounterStatus = static_cast<RequiredArgsNumber>(newArgumentsCount);
    argumentsCount = newArgumentsCount;
}


bool WorkFlow::ArgumentsHandler::getStatusConsoleInputStream() const {
    return isConsoleInputStream;
}

bool WorkFlow::ArgumentsHandler::getStatusConsoleOutputStream() const {
    return isConsoleOutputStream;
}

void WorkFlow::ArgumentsHandler::setArgumentsValues(char **newArgumentValues) {
    for (unsigned int i = 0; i < argumentsCount; i++) {
        std::string currentValue(newArgumentValues[i]);
        argumentValues.push_back(currentValue);
    }
}

std::string WorkFlow::ArgumentsHandler::getSourceFileName() const {
    return sourceFileName;
}

std::string WorkFlow::ArgumentsHandler::getInputFileName() const {
    return inputFileName;
}

std::string WorkFlow::ArgumentsHandler::getOutputFileName() const {
    return outputFileName;
}

void WorkFlow::ArgumentsHandler::setInputFileName(const std::string &newInputFileName) {
    inputFileName = newInputFileName;
}

void WorkFlow::ArgumentsHandler::setOutputFileName(const std::string &newOutputFileName) {
    outputFileName = newOutputFileName;
}

void WorkFlow::ArgumentsHandler::setSourceFileName() {
    sourceFileName = argumentValues[1];
}
