//
// Created by ulkenauer on 27.02.2021.
//

#ifndef EXAMPLE_WRAPPEDREDUCERFACTORY_H
#define EXAMPLE_WRAPPEDREDUCERFACTORY_H

// MUST BE GENERATED

#include <set>
#include <string>
#include "../../State.h"
#include "../ChangeDescriptionReducer.h"
#include <redux/WrappedReducer.h>

class WrappedReducerFactory {
public:
    WrappedReducerFactory() = default;
    WrappedReducer<State> wrap(const std::shared_ptr<ChangeDescriptionReducer>& reducer);
    std::set<std::string> knownActionTypes;
    std::set<std::string> knownReducerTypes;
};


#endif //EXAMPLE_WRAPPEDREDUCERFACTORY_H
