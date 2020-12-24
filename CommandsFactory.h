//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_FACTORY_H
#define LAB_2_FACTORY_H

#include "ICommandCreator.h"

namespace WorkFlowFactory {

    class CommandsFactory {
    private:

        std::map<std::string, WorkFlowFactory::ICommandCreator *> commandCreatorsMap;

    public:

        void registerCommandCreator(const std::string &commandName, WorkFlowFactory::ICommandCreator *commandCreator);

        WorkFlowFactory::ICommand *create(const std::string &commandName);
    };

}

#endif //LAB_2_FACTORY_H
