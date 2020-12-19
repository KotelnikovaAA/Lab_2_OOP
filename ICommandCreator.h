//
// Created by Anna on 23.11.2020.
//

#ifndef LAB_2_ICREATOR_H
#define LAB_2_ICREATOR_H

#include "ICommand.h"

namespace WorkFlowFactory {

    class ICommandCreator {
    public:
        virtual ~ICommandCreator() = default;

        [[nodiscard]] virtual ICommand *create() const = 0;
    };

}
#endif //LAB_2_ICREATOR_H
