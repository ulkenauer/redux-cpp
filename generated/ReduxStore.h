//
// Created by ulkenauer on 03.02.2021.
//

#ifndef EXAMPLE_REDUXSTORE_H
#define EXAMPLE_REDUXSTORE_H

#include <map>
#include <list>
#include <string>
#include <memory>
#include "State.h"
#include "Action.h"
#include "Reducer.h"

class ReduxStore {
public:
    ReduxStore();
    std::shared_ptr<State> state;
    std::list<std::shared_ptr<Reducer>> reducers;
    std::map<std::string, void (*)(ReduxStore *store, std::shared_ptr<Reducer> reducer, std::shared_ptr<Action> action)> preparers;

    void dispatch(const std::shared_ptr<Action>& action);
};

extern std::set<std::string> knownReducerTypes;
extern std::set<std::string> knownActionTypes;

#endif //EXAMPLE_REDUXSTORE_H
