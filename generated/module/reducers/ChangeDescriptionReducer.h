
#ifndef ChangeDescriptionReducer_H
#define ChangeDescriptionReducer_H


#include <memory>
#include "../actions/ChangeDescriptionAction.h"
#include <redux/IReducer.h>
#include "../generated/State.h"

class ChangeDescriptionReducer : public virtual IReducer<State> {
public:
    std::shared_ptr<State> state;
    std::shared_ptr<ChangeDescriptionAction> action;

    ChangeDescriptionReducer() = default;
    std::shared_ptr<State> reduce() override;
};


#endif //ChangeDescriptionReducer_H

