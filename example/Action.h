//
// Created by ulkenauer on 04.02.2021.
//

#ifndef EXAMPLE_ACTION_H
#define EXAMPLE_ACTION_H

#include <string>
#include <set>

class Action {
public:
    virtual std::string getActionType() = 0;
};

#endif //EXAMPLE_ACTION_H
