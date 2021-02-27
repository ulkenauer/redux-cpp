
#ifndef ChangeDescriptionReducer_H
#define ChangeDescriptionReducer_H


#include <memory>
#include "../actions/ChangeDescriptionAction.h"
#include <redux/IReducer.h>
#include "../State.h"

class ChangeDescriptionReducer : public virtual IReducer<State> {
private:
    std::shared_ptr<State> state;
    std::shared_ptr<ChangeDescriptionAction> action;
public:
    ChangeDescriptionReducer() = default;
    void prepare(std::shared_ptr<State> state, std::shared_ptr<ChangeDescriptionAction> action);
    std::shared_ptr<State> reduce() override;
};


#endif //ChangeDescriptionReducer_H

