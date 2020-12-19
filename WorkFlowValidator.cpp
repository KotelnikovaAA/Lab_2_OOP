//
// Created by Anna on 28.11.2020.
//

#include "WorkFlowValidator.h"
#include <string>
#include <map>

#define READFILE_CODE 1
#define WRITEFILE_CODE 2
#define GREP_CODE 3
#define SORT_CODE 4
#define REPLACE_CODE 5
#define DUMP_CODE 6

#define READFILE_COUNT_ARGS 1
#define WRITEFILE_COUNT_ARGS 1
#define GREP_COUNT_ARGS 1
#define SORT_COUNT_ARGS 0
#define REPLACE_COUNT_ARGS 2
#define DUMP_COUNT_ARGS 1


static unsigned int getCommandCode(const std::string &commandName) {

    std::map<std::string, unsigned int> commandNameCodeMap;

    commandNameCodeMap["readfile"] = READFILE_CODE;
    commandNameCodeMap["writefile"] = WRITEFILE_CODE;
    commandNameCodeMap["grep"] = GREP_CODE;
    commandNameCodeMap["sort"] = SORT_CODE;
    commandNameCodeMap["replace"] = REPLACE_CODE;
    commandNameCodeMap["dump"] = DUMP_CODE;

    return commandNameCodeMap.at(commandName);
}

unsigned int WorkFlow::WorkFlowValidator::checkCommandName(const std::string &funcName) {

    unsigned int commandCode = getCommandCode(funcName);

    switch (commandCode) {
        case READFILE_CODE:
            return READFILE_COUNT_ARGS;
        case WRITEFILE_CODE:
            return WRITEFILE_COUNT_ARGS;
        case GREP_CODE:
            return GREP_COUNT_ARGS;
        case SORT_CODE:
            return SORT_COUNT_ARGS;
        case REPLACE_CODE:
            return REPLACE_COUNT_ARGS;
        case DUMP_CODE:
            return DUMP_COUNT_ARGS;
        default:
            throw std::runtime_error("Validator error: The source file contains unidentified command.");
    }
}

bool WorkFlow::WorkFlowValidator::checkStringIsInitialBorder(const std::string &border) {
    if (border != "desc") {
        throw std::runtime_error("Validator error: The source file doesn't include initial border.");
    }
    return true;
}

bool WorkFlow::WorkFlowValidator::checkStringIsFiniteBorder(const std::string &border) {
    return border == "csed";
}

long int WorkFlow::WorkFlowValidator::checkValueIsNumber(const std::string &value) {
    return std::stol(value, nullptr, 10);
}

void WorkFlow::WorkFlowValidator::checkStringIsEqually(const std::string &verifiableStr) {
    if (verifiableStr != "=") {
        throw std::runtime_error("Validator error: One of the lines expected '=', but other data was found.");
    }
}

void WorkFlow::WorkFlowValidator::checkStringIsArrow(const std::string &verifiableStr) {
    if (verifiableStr != "->") {
        throw std::runtime_error("Validator error: One of the lines expected '->', but other data was found.");
    }
}
