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

    if (argumentsCount == static_cast<unsigned int>(WorkFlow::RequiredArgsNumber::WITH_IN_OR_OUT_FILE)) {
        if (argumentValues[2] == IS_INPUT_RUN_KEY) {
            isConsoleInputStream = true;
            setInputFileName(argumentValues[3]);
        } else if (argumentValues[2] == IS_OUTPUT_RUN_KEY) {
            isConsoleOutputStream = true;
            setOutputFileName(argumentValues[3]);
        } else {
            throw std::runtime_error("ArgHandler error: The arguments string has invalid format.");
        }
    }

    if (argumentsCount == static_cast<unsigned int>(WorkFlow::RequiredArgsNumber::WITH_IN_AND_OUT_FILES)) {
        if (argumentValues[2] == IS_INPUT_RUN_KEY && argumentValues[4] == IS_OUTPUT_RUN_KEY) {
            isConsoleInputStream = true;
            isConsoleOutputStream = true;
            setInputFileName(argumentValues[3]);
            setOutputFileName(argumentValues[5]);
        } else if (argumentValues[2] == IS_OUTPUT_RUN_KEY && argumentValues[4] == IS_INPUT_RUN_KEY) {
            isConsoleInputStream = true;
            isConsoleOutputStream = true;
            setInputFileName(argumentValues[5]);
            setOutputFileName(argumentValues[3]);
        } else {
            throw std::runtime_error("ArgHandler error: The arguments string has invalid format.");
        }
    }


}

void WorkFlow::ArgumentsHandler::setArgumentsCount(unsigned int newArgumentsCount) {
    checkCorrectArgsCounter(newArgumentsCount);
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
