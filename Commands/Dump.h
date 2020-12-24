//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_DUMP_H
#define LAB_2_DUMP_H

#include "../ExecutionContext.h"
#include "../ICommand.h"
#include "../CommandCreator.h"

namespace Commands {

    class Dump : public WorkFlowFactory::ICommand {
        void execute(WorkFlow::ExecutionContext &executionWorkFlowContext, unsigned int id) override;
    };

}

#endif //LAB_2_DUMP_H
