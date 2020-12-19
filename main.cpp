#include <iostream>
#include "WorkFlowExecutor.h"
#include "WorkFlowParser.h"
#include "ArgumentsHandler.h"

int main(int argc, char *argv[]) {

    WorkFlow::ArgumentsHandler argHandler{};

    try {
        argHandler.setArgumentsCount(argc);
        argHandler.setArgumentsValues(argv);
        argHandler.checkArgumentValues();
    } catch (std::runtime_error &exception) {
        std::cout << exception.what() << std::endl;
        return 0;
    }

    WorkFlow::WorkFlowParser parser;
    parser.setSourceFileName(argHandler.getSourceFileName());
    try {
        parser.runParser(argHandler.getStatusConsoleInputStream(), argHandler.getStatusConsoleOutputStream(),
                         argHandler.getInputFileName(), argHandler.getOutputFileName());
    } catch (std::runtime_error &exception) {
        std::cout << exception.what() << std::endl;
        return 0;
    } catch (std::out_of_range &exception) {
        std::cout << exception.what() << std::endl;
        return 0;
    }

    WorkFlow::WorkFlowExecutor workFlowExecutor;
    workFlowExecutor.setExecutionContextParams(parser.getArgumentsByIdMap(), parser.getCommandNamesByIdMap(),
                                               parser.getCommandOrder());
    try {
        workFlowExecutor.run();
    } catch (std::runtime_error &exception) {
        std::cout << exception.what() << std::endl;
    }

    return EXIT_SUCCESS;
}
