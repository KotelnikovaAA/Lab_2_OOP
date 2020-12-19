//
// Created by Anna on 27.11.2020.
//

#include "ExecutionContext.h"

std::vector<std::string> WorkFlow::ExecutionContext::getArgumentsById(const unsigned int id) const {
    return idArgumentsMap.at(id);
}

std::string WorkFlow::ExecutionContext::getNameCommandById(const unsigned int id) const {
    return idNameCommandsMap.at(id);
}

void
WorkFlow::ExecutionContext::setExecutionContext(const std::map<unsigned int, std::vector<std::string>> &installIdArgumentsMap,
                                      const std::map<unsigned int, std::string> &installIdNameCommandsMap,
                                      const std::vector<unsigned int> &installCommandOrder) {
    idArgumentsMap = installIdArgumentsMap;
    idNameCommandsMap = installIdNameCommandsMap;
    commandOrder = installCommandOrder;
}

void WorkFlow::ExecutionContext::addNewStringToText(const std::string &newString) {
    executionText.push_back(newString);
}

std::vector<std::string> WorkFlow::ExecutionContext::getExecutionText() const {
    return executionText;
}

void WorkFlow::ExecutionContext::setExecutionText(const std::vector<std::string> &newText) {
    executionText = newText;
}

std::vector<unsigned int> WorkFlow::ExecutionContext::getCommandOrder() const {
    return commandOrder;
}
