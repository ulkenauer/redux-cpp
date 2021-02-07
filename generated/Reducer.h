//
// Created by ulkenauer on 05.02.2021.
//

#ifndef EXAMPLE_REDUCER_H
#define EXAMPLE_REDUCER_H

#include <set>
#include <string>
#include <memory>
#include "State.h"

class Reducer {
public:
    virtual std::string getActionType() = 0;
    virtual std::string getReducerType() = 0;

    virtual std::shared_ptr<State> reduce() = 0;
};

#endif //EXAMPLE_REDUCER_H
