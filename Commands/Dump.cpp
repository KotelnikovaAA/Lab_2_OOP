//
// Created by Anna on 23.11.2020.
//

#include "Dump.h"
#include <fstream>
#include <string>

void Commands::Dump::execute(WorkFlow::ExecutionContext &executionWorkFlowContext, const unsigned int id) {
    std::ofstream outputFile;
    std::string fileName = executionWorkFlowContext.getArgumentsById(id).front();

    outputFile.open(fileName);

    if (!outputFile.is_open()) {
        throw std::runtime_error("Dump error: Couldn't open file... Program stopped");
    }

    for (const auto &curString : executionWorkFlowContext.getExecutionText()) {
        outputFile << curString << std::endl;
    }

    outputFile.close();
}
