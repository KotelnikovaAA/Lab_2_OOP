//
// Created by Anna on 02.12.2020.
//

#ifndef LAB_2_ARGUMENTSHANDLER_H
#define LAB_2_ARGUMENTSHANDLER_H

#include <iostream>
#include <vector>


namespace WorkFlow {

    enum class RequiredArgsNumber {
        WITHOUT_IN_AND_OUT_FILES = 2,
        WITH_IN_OR_OUT_FILE = 4,
        WITH_IN_AND_OUT_FILES = 6
    };

    const std::string IS_INPUT_RUN_KEY = "-i";
    const std::string IS_OUTPUT_RUN_KEY = "-o";

    class ArgumentsHandler {

    private:

        RequiredArgsNumber argumentsCounterStatus;

        unsigned int argumentsCount;

        std::vector<std::string> argumentValues;

        bool isConsoleInputStream = false;

        bool isConsoleOutputStream = false;

        std::string sourceFileName;

        std::string inputFileName;

        std::string outputFileName;

        void setSourceFileName();

    public:

        void setArgumentsCount(unsigned int newArgumentsCount);

        void setInputFileName(const std::string &newInputFileName);

        void setOutputFileName(const std::string &newOutputFileName);

        void setArgumentsValues(char **newArgumentValues);

        [[nodiscard]] std::string getSourceFileName() const;

        [[nodiscard]] std::string getInputFileName() const;

        [[nodiscard]] std::string getOutputFileName() const;

        [[nodiscard]] bool getStatusConsoleInputStream() const;

        [[nodiscard]] bool getStatusConsoleOutputStream() const;

        void checkArgumentValues();
    };

}
#endif //LAB_2_ARGUMENTSHANDLER_H
