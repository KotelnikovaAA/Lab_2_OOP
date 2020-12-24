//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_REPLACE_H
#define LAB_2_REPLACE_H

#include "../ExecutionContext.h"
#include "../ICommand.h"

namespace Commands {

    static const unsigned int FIRST_REPLACE_ARGS_INDEX = 0;
    static const unsigned int SECOND_REPLACE_ARGS_INDEX = 1;

    class Replace : public WorkFlowFactory::ICommand {
        void execute(WorkFlow::ExecutionContext &executionWorkFlowContext, unsigned int id) override;

    };

}
#endif //LAB_2_REPLACE_H
