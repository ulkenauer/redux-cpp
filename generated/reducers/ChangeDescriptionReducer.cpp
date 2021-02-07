
#include "ChangeDescriptionReducer.h"

std::shared_ptr<State> ChangeDescriptionReducer::reduce() {
    StateBuilder builder = StateBuilder();
    builder.setState(*this->state);
    
    // TODO: implement reducer
    builder.description = action->description;

    builder.build();

    return std::make_shared<State>(builder.getState());
}
