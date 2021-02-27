//
// Created by ulkenauer on 27.02.2021.
//

#ifndef EXAMPLE_STOREBUILDER_H
#define EXAMPLE_STOREBUILDER_H

// MUST BE GENERATED

#include <set>

#include "utils/WrappedActionFactory.h"
#include "utils/WrappedReducerFactory.h"
#include <redux/ReduxStore.h>

class StoreBuilder {
public:
    StoreBuilder();
    WrappedActionFactory actionFactory;
    WrappedReducerFactory reducerFactory;

    std::set<std::string> knownActionTypes;
    std::set<std::string> knownReducerTypes;

    ReduxStore<State> build();
};


#endif //EXAMPLE_STOREBUILDER_H
