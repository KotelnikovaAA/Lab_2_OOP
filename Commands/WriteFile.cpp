//
// Created by Anna on 23.11.2020.
//

#include "WriteFile.h"

#include <fstream>
#include <string>

void Commands::WriteFile::execute(WorkFlow::ExecutionContext &executionWorkFlowContext, const unsigned int id) {
    std::ofstream outputFile;
    std::string fileName = executionWorkFlowContext.getArgumentsById(id).front();
    outputFile.open(fileName);

    if (!outputFile.is_open()) {
        throw std::runtime_error("WriteFile error: Couldn't open file... Program stopped.");
    }

    for (const auto &curString : executionWorkFlowContext.getExecutionText()) {
        outputFile << curString << std::endl;
    }

    outputFile.close();
}
