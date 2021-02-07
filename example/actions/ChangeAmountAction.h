//
// Created by ulkenauer on 04.02.2021.
//

#ifndef EXAMPLE_CHANGEAMOUNTACTION_H
#define EXAMPLE_CHANGEAMOUNTACTION_H

#include "../Action.h"

class ChangeAmountAction : public Action {
public:
    ChangeAmountAction(int amount);

    int getAmount();

    std::string getActionType() override;

private:
    int amount;
};


#endif //EXAMPLE_CHANGEAMOUNTACTION_H
