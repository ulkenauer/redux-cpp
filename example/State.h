//
// Created by ulkenauer on 04.02.2021.
//

#ifndef EXAMPLE_STATE_H
#define EXAMPLE_STATE_H


class State {
public:
    State() = default;

    State(const State &state) = default;
    explicit State(int amount);

    int getAmount() const
    {
        return this->amount;
    }

private:
    int amount;
};

class StateBuilder {
public:
    StateBuilder() = default;
    void setState(State state);
    State getState();

    int amount;
    State state;

    void build();
};

#endif //EXAMPLE_STATE_H
