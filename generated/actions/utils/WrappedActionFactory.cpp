//
// Created by ulkenauer on 27.02.2021.
//

// MUST BE GENERATED

#include "WrappedActionFactory.h"

WrappedAction WrappedActionFactory::wrap(const std::shared_ptr<ChangeDescriptionAction>& action) {
    WrappedAction wrappedAction = WrappedAction();
    wrappedAction.metadata = ActionMetadata();
    wrappedAction.metadata.actionType = *this->knownActionTypes.find("ChangeDescriptionAction");
    wrappedAction.action = action;
    return wrappedAction;
}
