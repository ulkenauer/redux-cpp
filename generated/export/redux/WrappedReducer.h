//
// Created by ulkenauer on 27.02.2021.
//

// CLEAN EXTRACT

#ifndef EXAMPLE_WRAPPEDREDUCER_H
#define EXAMPLE_WRAPPEDREDUCER_H


#include <memory>
#include "ReducerMetadata.h"
#include "IReducer.h"

template<class StateType>
class WrappedReducer {
    public:
        ReducerMetadata metadata;
        std::shared_ptr<IReducer<StateType>> reducer;
};


#endif //EXAMPLE_WRAPPEDREDUCER_H
