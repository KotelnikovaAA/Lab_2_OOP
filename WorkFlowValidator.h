//
// Created by Anna on 28.11.2020.
//

#ifndef LAB_2_WORKFLOWVALIDATOR_H
#define LAB_2_WORKFLOWVALIDATOR_H


#include <string>

namespace WorkFlow {

    class WorkFlowValidator {
    public:
        static unsigned int checkCommandName(const std::string &funcName);

        static bool checkStringIsInitialBorder(const std::string &border);

        static bool checkStringIsFiniteBorder(const std::string &border);

        static long int checkValueIsNumber(const std::string &value);

        static void checkStringIsEqually(const std::string &verifiableStr);

        static void checkStringIsArrow(const std::string &verifiableStr);
    };

}

#endif //LAB_2_WORKFLOWVALIDATOR_H
