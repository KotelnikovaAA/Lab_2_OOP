//
// Created by Anna on 23.11.2020.
//

#include "ReadFile.h"
#include <fstream>
#include <string>

#include "../CommandCreator.h"

REGISTER_CREATOR(Commands::ReadFile, "readfile");

void Commands::ReadFile::execute(WorkFlow::ExecutionContext &executionWorkFlowContext, const unsigned int id) {
    std::ifstream inputFile;
    std::string fileName = executionWorkFlowContext.getArgumentsById(id).front();
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        throw std::runtime_error("ReadFile error: Couldn't open file... Program stopped.");
    }

    std::string partOfText;
    while (std::getline(inputFile, partOfText)) {
        executionWorkFlowContext.addNewStringToText(partOfText);
    }

    inputFile.close();
}
