

/** 
 ** GENERATED FILE
 ** DO NOT EDIT
 **/
 

#include "reducers/ChangeDescriptionReducer.h"
#include "actions/ChangeDescriptionAction.h"
#include "actions/ChangeTagAction.h"
#include "ReduxStore.h"

void initializeReducerTypes()
{
    knownReducerTypes = std::set<std::string>();
    knownReducerTypes.insert("ChangeDescriptionReducer");
}

void initializeActionTypes()
{
    knownActionTypes = std::set<std::string>();
    knownActionTypes.insert("ChangeDescriptionAction");
knownActionTypes.insert("ChangeTagAction");
}

//Preparers

void prepareChangeDescriptionReducer(ReduxStore *store, std::shared_ptr<Reducer> reducer, std::shared_ptr<Action> action)
{
    std::shared_ptr<ChangeDescriptionAction> targetAction = std::static_pointer_cast<ChangeDescriptionAction>(action);
    std::shared_ptr<ChangeDescriptionReducer> targetReducer = std::dynamic_pointer_cast<ChangeDescriptionReducer>(reducer);
    targetReducer->prepare(store->state, targetAction);
}    


void initializeReducers(ReduxStore* store)
{
    store->preparers = std::map<std::string, void (*)(ReduxStore *store, std::shared_ptr<Reducer> reducer, std::shared_ptr<Action> action)>();
    store->reducers = std::list<std::shared_ptr<Reducer>>();
    
    
    store->preparers["ChangeDescriptionReducer"] = &prepareChangeDescriptionReducer;
    store->reducers.push_back(std::make_shared<ChangeDescriptionReducer>());

    
}
