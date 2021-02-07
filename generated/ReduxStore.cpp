#include "ReduxStore.h"
#include <memory>

void initializeReducerTypes();
void initializeActionTypes();
void initializeTypes();

void initializeReducers(ReduxStore* store);

ReduxStore::ReduxStore() : state(std::make_shared<State>()) {
    initializeTypes();
    initializeReducers(this);
}

void ReduxStore::dispatch(const std::shared_ptr<Action>& action) {
    for (const auto& reducer : this->reducers) {
        if (reducer->getActionType() == action->getActionType()) {
            this->preparers[reducer->getReducerType()](this, reducer, action);
            this->state = reducer->reduce();
        }
    }
}

std::set<std::string> knownReducerTypes;
std::set<std::string> knownActionTypes;

bool typesAreInitialized = false;

void initializeTypes()
{
    if (!typesAreInitialized) {
        initializeActionTypes();
        initializeReducerTypes();
    }

    typesAreInitialized = true;
}