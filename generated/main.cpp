#include <iostream>
#include "ReduxStore.h"
#include "actions/ChangeDescriptionAction.h"
#include <set>
#include <string>
#include <memory>


void storeTest()
{
//    auto state = AppState("asd", 2, "qw");
//    auto builder = AppStateBuilder();
//    std::cout << state.getDescription() << " " << state.getQuantity() << " " << state.getTag() << " " << std::endl;
//    builder.setState(state);
//    builder.quantity = 228;
//    builder.build();
//    state = builder.getState();
//    std::cout << state.getDescription() << " " << state.getQuantity() << " " << state.getTag() << " " << std::endl;
//    return;

    auto store = ReduxStore();
    std::cout << "hehe" << std::endl;
    auto action = std::make_shared<ChangeDescriptionAction>();
    auto action2 = std::make_shared<ChangeDescriptionAction>();
    action->description = "bruh";
    action2->description = "new description";
    store.dispatch(action);
    std::cout << store.state->getDescription() << std::endl;
    store.dispatch(action2);
    std::cout << store.state->getDescription() << std::endl;

//    store.dispatch(std::make_shared<ChangeAmountAction>(3));
//    std::cout << store.state->getAmount() << std::endl;
//    store.dispatch(std::make_shared<ChangeAmountAction>(13));
//    std::cout << store.state->getAmount() << std::endl;

}

int main() {
    storeTest();
////    std::set<std::string> knownActionTypes;
////    knownActionTypes.insert("ChangeAmountAction");
////    std::cout << (*knownActionTypes.find("ChangeAmountAction")) << std::endl;
////    return 0;
//
//    auto item = TestClass();
//    item.quantity = 37;
//    auto item2 = item.clone();
//    item.quantity = 2222;
//    std::cout << item.quantity << "  " << item2.quantity << " Hello, World!" << std::endl;
    return 0;
}
