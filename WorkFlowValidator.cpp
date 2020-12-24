//
// Created by Anna on 28.11.2020.
//

#include "WorkFlowValidator.h"
#include <string>
#include <map>

unsigned int WorkFlow::WorkFlowValidator::checkCommandName(const std::string &funcName) {

    OperationsCode commandCode = getOperationCode(funcName);

    switch (commandCode) {
        case OperationsCode::READFILE:
            return static_cast<unsigned int>(OperationsCountArgs::READFILE);
        case OperationsCode::WRITEFILE:
            return static_cast<unsigned int>(OperationsCountArgs::WRITEFILE);
        case OperationsCode::GREP:
            return static_cast<unsigned int>(OperationsCountArgs::GREP);
        case OperationsCode::SORT:
            return static_cast<unsigned int>(OperationsCountArgs::SORT);
        case OperationsCode::REPLACE:
            return static_cast<unsigned int>(OperationsCountArgs::REPLACE);
        case OperationsCode::DUMP:
            return static_cast<unsigned int>(OperationsCountArgs::DUMP);
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

WorkFlow::OperationsCode WorkFlow::WorkFlowValidator::getOperationCode(const std::string &commandName) {
    std::map<std::string, OperationsCode> commandNameCodeMap;

    commandNameCodeMap["readfile"] = OperationsCode::READFILE;
    commandNameCodeMap["writefile"] = OperationsCode::WRITEFILE;
    commandNameCodeMap["grep"] = OperationsCode::GREP;
    commandNameCodeMap["sort"] = OperationsCode::SORT;
    commandNameCodeMap["replace"] = OperationsCode::REPLACE;
    commandNameCodeMap["dump"] = OperationsCode::DUMP;

    return commandNameCodeMap.at(commandName);
}
