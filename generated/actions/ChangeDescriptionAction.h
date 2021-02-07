
#ifndef ChangeDescriptionAction_H
#define ChangeDescriptionAction_H

#include "../Action.h"

class ChangeDescriptionAction : public Action {
public:
    std::string getActionType() override;

    std::string description;
    ChangeDescriptionAction() = default;
    // TODO: action payload
};


#endif //ChangeDescriptionAction_H

