//
// Created by Anna on 23.11.2020.
//

#include "Grep.h"
#include <algorithm>

void Commands::Grep::execute(WorkFlow::ExecutionContext &executionWorkFlowContext, const unsigned int id) {

    std::vector<std::string> vectorForGrep;
    std::string searchWord = executionWorkFlowContext.getArgumentsById(id).front();

    for (const auto &curString : executionWorkFlowContext.getExecutionText()) {
        if (curString.find(searchWord) != std::string::npos) {
            vectorForGrep.push_back(curString);
        }
    }

    executionWorkFlowContext.setExecutionText(vectorForGrep);
}
