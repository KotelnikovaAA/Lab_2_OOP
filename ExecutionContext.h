//
// Created by Anna on 27.11.2020.
//

#ifndef LAB_2_EXECUTIONCONTEXT_H
#define LAB_2_EXECUTIONCONTEXT_H

#include <vector>
#include <map>
#include <string>

namespace WorkFlow {

    class ExecutionContext {
    private:

        std::vector<std::string> executionText;

        std::map<unsigned int, std::vector<std::string>> idArgumentsMap;

        std::map<unsigned int, std::string> idNameCommandsMap;

        std::vector<unsigned int> commandOrder;

    public:

        void setExecutionContext(const std::map<unsigned int, std::vector<std::string>> &installIdArgumentsMap,
                                 const std::map<unsigned int, std::string> &installIdNameCommandsMap,
                                 const std::vector<unsigned int> &installCommandOrder);

        void addNewStringToText(const std::string &newString);

        [[nodiscard]] std::vector<std::string> getArgumentsById(unsigned int id) const;

        [[nodiscard]] std::string getNameCommandById(unsigned int id) const;

        [[nodiscard]] std::vector<std::string> getExecutionText() const;

        [[nodiscard]] std::vector<unsigned int> getCommandOrder() const;

        void setExecutionText(const std::vector<std::string> &newText);

    };

}

#endif //LAB_2_EXECUTIONCONTEXT_H
