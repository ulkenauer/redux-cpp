//
// Created by ulkenauer on 27.02.2021.
//

#include <memory>
#include "WrappedReducerFactory.h"

WrappedReducer<State> WrappedReducerFactory::wrap(const std::shared_ptr<ChangeDescriptionReducer>& reducer) {
    WrappedReducer<State> wrappedReducer = WrappedReducer<State>();
    wrappedReducer.metadata = ReducerMetadata();
    wrappedReducer.metadata.actionType = *this->knownActionTypes.find("ChangeDescriptionAction");
    wrappedReducer.metadata.reducerType = *this->knownReducerTypes.find("ChangeDescriptionReducer");
    wrappedReducer.reducer = reducer;
    return wrappedReducer;
}