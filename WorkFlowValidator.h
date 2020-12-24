//
// Created by Anna on 28.11.2020.
//

#ifndef LAB_2_WORKFLOWVALIDATOR_H
#define LAB_2_WORKFLOWVALIDATOR_H


#include <string>

namespace WorkFlow {

    enum class OperationsCode {
        READFILE,
        WRITEFILE,
        GREP,
        SORT,
        REPLACE,
        DUMP
    };

    enum class OperationsCountArgs {
        READFILE = 1,
        WRITEFILE = 1,
        GREP = 1,
        SORT = 0,
        REPLACE = 2,
        DUMP = 1
    };

    class WorkFlowValidator {
    public:
        static unsigned int checkCommandName(const std::string &funcName);

        static bool checkStringIsInitialBorder(const std::string &border);

        static bool checkStringIsFiniteBorder(const std::string &border);

        static long int checkValueIsNumber(const std::string &value);

        static void checkStringIsEqually(const std::string &verifiableStr);

        static void checkStringIsArrow(const std::string &verifiableStr);

    private:
        static OperationsCode getOperationCode(const std::string &commandName);
    };

}

#endif //LAB_2_WORKFLOWVALIDATOR_H
