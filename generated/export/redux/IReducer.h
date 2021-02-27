//
// Created by ulkenauer on 05.02.2021.
//

#ifndef EXAMPLE_IREDUCER_H
#define EXAMPLE_IREDUCER_H

#include <set>
#include <string>
#include <memory>

// CLEAN EXTRACT

template<class StateType>
class IReducer {
public:
    virtual std::shared_ptr<StateType> reduce() = 0;
};

#endif //EXAMPLE_IREDUCER_H
