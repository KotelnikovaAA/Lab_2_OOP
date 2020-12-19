//
// Created by Anna on 23.11.2020.
//

#include "Sort.h"
#include <algorithm>

#include "../CommandCreator.h"

REGISTER_CREATOR(Commands::Sort, "sort");

void Commands::Sort::execute(WorkFlow::ExecutionContext &executionWorkFlowContext, unsigned int id) {

    std::vector<std::string> vectorForSort = executionWorkFlowContext.getExecutionText();
    std::sort(vectorForSort.begin(), vectorForSort.end());

    executionWorkFlowContext.setExecutionText(vectorForSort);

}
