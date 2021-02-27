//
// Created by ulkenauer on 27.02.2021.
//

// MUST BE GENERATED

#include "StoreBuilder.h"

StoreBuilder::StoreBuilder() {
    this->knownReducerTypes.insert("ChangeDescriptionReducer");

    this->knownActionTypes.insert("ChangeDescriptionAction");
    this->knownActionTypes.insert("ChangeTagAction");

    this->actionFactory.knownActionTypes = this->knownActionTypes;

    this->reducerFactory.knownActionTypes = this->knownActionTypes;
    this->reducerFactory.knownReducerTypes = this->knownReducerTypes;
}

void prepareChangeDescriptionReducer(ReduxStore<State> *store, std::shared_ptr<IReducer<State>> reducer, std::shared_ptr<void> action)
{
    std::shared_ptr<ChangeDescriptionAction> targetAction = std::static_pointer_cast<ChangeDescriptionAction>(action);
    std::shared_ptr<ChangeDescriptionReducer> targetReducer = std::dynamic_pointer_cast<ChangeDescriptionReducer>(reducer);
    targetReducer->state = store->state;
    targetReducer->action = targetAction;
}

ReduxStore<State> StoreBuilder::build() {
    ReduxStore<State> reduxStore = ReduxStore<State>();

    reduxStore.preparers = std::map<std::string, void (*)(ReduxStore<State> *store, std::shared_ptr<IReducer<State>> reducer, std::shared_ptr<void> action)>();
    reduxStore.reducers = std::list<WrappedReducer<State>>();

    reduxStore.preparers["ChangeDescriptionReducer"] = &prepareChangeDescriptionReducer;
    reduxStore.reducers.push_back(this->reducerFactory.wrap(std::make_shared<ChangeDescriptionReducer>()));

    return reduxStore;
}
