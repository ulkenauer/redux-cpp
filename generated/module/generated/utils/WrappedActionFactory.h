//
// Created by ulkenauer on 27.02.2021.
//

// MUST BE GENERATED

#ifndef EXAMPLE_WRAPPEDACTIONFACTORY_H
#define EXAMPLE_WRAPPEDACTIONFACTORY_H

#include "../../actions/ChangeDescriptionAction.h"
#include <set>
#include <redux/WrappedAction.h>

class WrappedActionFactory {
    public:
    WrappedActionFactory() = default;
    WrappedAction wrap(const std::shared_ptr<ChangeDescriptionAction>& action);
    std::set<std::string> knownActionTypes;
};


#endif //EXAMPLE_WRAPPEDACTIONFACTORY_H
