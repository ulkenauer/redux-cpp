
#ifndef ChangeTagAction_H
#define ChangeTagAction_H

#include "../Action.h"

class ChangeTagAction : public Action {
public:
    std::string getActionType() override;
    // TODO: action payload
};


#endif //ChangeTagAction_H

