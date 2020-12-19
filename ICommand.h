//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_ICOMMAND_H
#define LAB_2_ICOMMAND_H

#include "ExecutionContext.h"

namespace WorkFlowFactory {

    class ICommand {

    public:
        virtual void execute(WorkFlow::ExecutionContext &executionWorkFlowContext, unsigned int id) = 0;

        virtual ~ICommand() = default;
    };

}

#endif //LAB_2_ICOMMAND_H