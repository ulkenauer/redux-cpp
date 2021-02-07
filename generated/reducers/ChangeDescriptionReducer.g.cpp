

/** 
 ** GENERATED FILE
 ** DO NOT EDIT
 **/
 
#include "ChangeDescriptionReducer.h"
#include "../ReduxStore.h"

std::string ChangeDescriptionReducer::getReducerType() {
    //todo: add check
    return *knownReducerTypes.find("ChangeDescriptionReducer");
}

std::string ChangeDescriptionReducer::getActionType() {
    //todo: add check
    return *knownActionTypes.find("ChangeDescriptionAction");
}

void ChangeDescriptionReducer::prepare(std::shared_ptr<State> state, std::shared_ptr<ChangeDescriptionAction> action) {
    this->state = state;
    this->action = action;
}
