//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_SORT_H
#define LAB_2_SORT_H

#include "../ExecutionContext.h"
#include "../ICommand.h"

namespace Commands {

    class Sort : public WorkFlowFactory::ICommand {
        void execute(WorkFlow::ExecutionContext &executionWorkFlowContext, unsigned int id) override;
    };

}

#endif //LAB_2_SORT_H
