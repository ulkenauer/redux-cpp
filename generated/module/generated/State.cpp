

/** 
 ** GENERATED FILE
 ** DO NOT EDIT
 **/
 
#include "State.h"

State::State(std::string description, int quantity, std::string tag) : description(description), quantity(quantity), tag(tag) {}

void StateBuilder::setState(State state) {
    
	this->description = state.getDescription();
	this->quantity = state.getQuantity();
	this->tag = state.getTag();
}

State StateBuilder::getState() {
    return this->state;
}


std::string State::getDescription() const {
    return this->description;
}

int State::getQuantity() const {
    return this->quantity;
}

std::string State::getTag() const {
    return this->tag;
}


void StateBuilder::build() {
    this->state = State(this->description, this->quantity, this->tag);
}
