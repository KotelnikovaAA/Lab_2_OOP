//
// Created by Anna on 27.11.2020.
//

#include "WorkFlowExecutor.h"
#include "ICommand.h"
#include "CommandsFactory.h"
#include <memory>

void
WorkFlow::WorkFlowExecutor::setExecutionContextParams(
        const std::map<unsigned int, std::vector<std::string>> &argumentsByIdMap,
        const std::map<unsigned int, std::string> &commandNamesByIdMap,
        const std::vector<unsigned int> &commandOrder) {
    executionWorkFlowContext.setExecutionContext(argumentsByIdMap, commandNamesByIdMap, commandOrder);
}

void WorkFlow::WorkFlowExecutor::run() {
    auto executionCommandOrder = executionWorkFlowContext.getCommandOrder();
    for (const auto &curCommandId : executionCommandOrder) {
        std::unique_ptr<WorkFlowFactory::ICommand> currentCommand(WorkFlowFactory::CommandsFactory::instance().create(
                executionWorkFlowContext.getNameCommandById(curCommandId)));
        currentCommand->execute(executionWorkFlowContext, curCommandId);
    }
}

