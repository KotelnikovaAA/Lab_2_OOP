//
// Created by Anna on 23.11.2020.
//

#include "CommandsFactory.h"
#include <string>

void
WorkFlowFactory::CommandsFactory::registerCommandCreator(const std::string &commandName,
                                                  WorkFlowFactory::ICommandCreator *commandCreator) {
    if (commandCreatorsMap.find(commandName) == commandCreatorsMap.end()) {
        commandCreatorsMap[commandName] = commandCreator;
    } else {
        throw std::runtime_error("Operation factory error: too much creators for given key");
    }
}

WorkFlowFactory::ICommand *WorkFlowFactory::CommandsFactory::create(const std::string &commandName) {
    auto iterator = commandCreatorsMap.find(commandName);
    if (iterator != commandCreatorsMap.end()) {
        return iterator->second->create();
    } else {
        throw std::runtime_error("Operation factory error: unknown command - " + commandName);
    }
}
