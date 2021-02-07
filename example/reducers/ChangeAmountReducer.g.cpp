#include "ChangeAmountReducer.h"
#include "../ReduxStore.h"

std::string ChangeAmountReducer::getReducerType() {
    //todo: add check
    return *knownReducerTypes.find("ChangeAmountReducer");
}

std::string ChangeAmountReducer::getActionType() {
    //todo: add check
    return *knownActionTypes.find("ChangeAmountAction");
}

void ChangeAmountReducer::prepare(std::shared_ptr<State> state, std::shared_ptr<ChangeAmountAction> action) {
    this->state = state;
    this->action = action;
}
