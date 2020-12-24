//
// Created by Anna on 27.11.2020.
//

#include "WorkFlowExecutor.h"
#include "ICommand.h"
#include "CommandsFactory.h"
#include "CommandCreator.h"
#include "Commands/Dump.h"
#include "Commands/Grep.h"
#include "Commands/ReadFile.h"
#include "Commands/Replace.h"
#include "Commands/Sort.h"
#include "Commands/WriteFile.h"
#include <memory>

void
WorkFlow::WorkFlowExecutor::setExecutionContextParams(
        const std::map<unsigned int, std::vector<std::string>> &argumentsByIdMap,
        const std::map<unsigned int, std::string> &commandNamesByIdMap,
        const std::vector<unsigned int> &commandOrder) {
    executionWorkFlowContext.setExecutionContext(argumentsByIdMap, commandNamesByIdMap, commandOrder);
}

void WorkFlow::WorkFlowExecutor::run() {
    WorkFlowFactory::CommandsFactory executorFactory;

    WorkFlowFactory::CommandCreator<Commands::Dump> dumpCreator("dump", executorFactory);
    WorkFlowFactory::CommandCreator<Commands::Grep> grepCreator("grep", executorFactory);
    WorkFlowFactory::CommandCreator<Commands::ReadFile> readFileCreator("readfile", executorFactory);
    WorkFlowFactory::CommandCreator<Commands::Replace> replaceCreator("replace", executorFactory);
    WorkFlowFactory::CommandCreator<Commands::Sort> sortCreator("sort", executorFactory);
    WorkFlowFactory::CommandCreator<Commands::WriteFile> writeFileCreator("writefile", executorFactory);

    auto executionCommandOrder = executionWorkFlowContext.getCommandOrder();
    for (const auto &curCommandId : executionCommandOrder) {
        std::unique_ptr<WorkFlowFactory::ICommand> currentCommand(executorFactory.create(
                executionWorkFlowContext.getNameCommandById(curCommandId)));
        currentCommand->execute(executionWorkFlowContext, curCommandId);
    }
}

