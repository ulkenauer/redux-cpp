//
// Created by ulkenauer on 04.02.2021.
//

#include "State.h"

State::State(int amount) : amount(amount) {}

void StateBuilder::setState(State state) {
    this->amount = state.getAmount();
}

State StateBuilder::getState() {
    return this->state;
}

void StateBuilder::build() {
    this->state = State(this->amount);
}
