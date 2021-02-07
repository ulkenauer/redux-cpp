
#ifndef ChangeDescriptionReducer_H
#define ChangeDescriptionReducer_H


#include <memory>
#include "../actions/ChangeDescriptionAction.h"
#include "../Reducer.h"

class ChangeDescriptionReducer : public virtual Reducer {
private:
    std::shared_ptr<State> state;
    std::shared_ptr<ChangeDescriptionAction> action;
public:
    ChangeDescriptionReducer() = default;
    void prepare(std::shared_ptr<State> state, std::shared_ptr<ChangeDescriptionAction> action);
    std::shared_ptr<State> reduce() override;
    std::string getActionType() override;
    std::string getReducerType() override;
};


#endif //ChangeDescriptionReducer_H

