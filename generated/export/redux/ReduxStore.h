//
// Created by ulkenauer on 03.02.2021.
//

#ifndef EXAMPLE_REDUXSTORE_H
#define EXAMPLE_REDUXSTORE_H

#include <map>
#include <list>
#include <string>
#include <memory>
#include "IReducer.h"
#include "WrappedAction.h"
#include "WrappedReducer.h"

// CLEAN EXTRACT

template<class StateType>
class ReduxStore {
public:
    ReduxStore();
    std::shared_ptr<StateType> state;
    std::list<WrappedReducer<StateType>> reducers;

    std::map<std::string, void (*)(ReduxStore<StateType> *store, std::shared_ptr<IReducer<StateType>> reducer, std::shared_ptr<void> action)> preparers;

    void dispatch(const WrappedAction& action);
};

template <class StateType>
ReduxStore<StateType>::ReduxStore() : state(std::make_shared<State>()) {}

template<class StateType>
void ReduxStore<StateType>::dispatch(const WrappedAction& action) {
    for (const auto& reducer : this->reducers) {
        if (reducer.metadata.actionType == action.metadata.actionType) {
            this->preparers[reducer.metadata.reducerType](this, reducer.reducer, action.action);
            this->state = reducer.reducer->reduce();
        }
    }
}

#endif //EXAMPLE_REDUXSTORE_H
