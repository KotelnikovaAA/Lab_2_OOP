//
// Created by Anna on 27.11.2020.
//

#ifndef LAB_2_WORKFLOWEXECUTOR_H
#define LAB_2_WORKFLOWEXECUTOR_H

#include "ExecutionContext.h"

namespace WorkFlow {

    class WorkFlowExecutor {
    public:
        void run();
        void setExecutionContextParams(const std::map<unsigned int, std::vector<std::string>> &argumentsByIdMap,
                                       const std::map<unsigned int, std::string> &commandNamesByIdMap,
                                       const std::vector<unsigned int> &commandOrder);

    private:
        ExecutionContext executionWorkFlowContext;
    };

}

#endif //LAB_2_WORKFLOWEXECUTOR_H
