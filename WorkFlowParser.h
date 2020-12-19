//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_PARSER_H
#define LAB_2_PARSER_H

#include <string>
#include <map>
#include <vector>

namespace WorkFlow {

    class WorkFlowParser {
    public:
        void setSourceFileName(const std::string &newSourceFileName);

        [[nodiscard]] std::map<unsigned int, std::vector<std::string>> getArgumentsByIdMap() const;

        [[nodiscard]] std::map<unsigned int, std::string> getCommandNamesByIdMap() const;

        [[nodiscard]] std::vector<unsigned int> getCommandOrder() const;

        void
        runParser(const bool isConsoleInputStream, const bool isConsoleOutputStream, const std::string &inputFileName,
                  const std::string &outputFileName);

    private:
        std::string sourceFileName;
        std::map<unsigned int, std::vector<std::string>> argumentsByIdMap;
        std::map<unsigned int, std::string> commandNamesByIdMap;
        std::vector<unsigned int> commandOrder;

        static void tryReadCurrentString(std::istringstream &stream, std::string &string);
    };

}

#endif //LAB_2_PARSER_H
