

/** 
 ** GENERATED FILE
 ** DO NOT EDIT
 **/
 
#ifndef State_H
#define State_H
#include <string>

class State {
public:
    State() = default;

    State(const State &state) = default;
    explicit State(std::string description, int quantity, std::string tag);

	std::string getDescription() const;
	int getQuantity() const;
	std::string getTag() const;

private:
	std::string description;
	int quantity;
	std::string tag;
};

class StateBuilder {
public:
    StateBuilder() = default;
    void setState(State state);
    State getState();

	std::string description;
	int quantity;
	std::string tag;

    void build();
private:
     State state;
};

#endif //State_H
