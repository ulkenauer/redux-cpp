#include <iostream>
#include "module/actions/ChangeDescriptionAction.h"
#include "module/generated/StoreBuilder.h"
#include <string>
#include <memory>

void storeTest()
{
    auto storeBuilder = StoreBuilder();
    auto store = storeBuilder.build();
    std::cout << "hehe" << std::endl;
    auto action = std::make_shared<ChangeDescriptionAction>();
    auto action2 = std::make_shared<ChangeDescriptionAction>();
    action->description = "bruh";
    action2->description = "new description";
    store.dispatch(storeBuilder.actionFactory.wrap(action));
    std::cout << store.state->getDescription() << std::endl;
    store.dispatch(storeBuilder.actionFactory.wrap(action2));
    std::cout << store.state->getDescription() << std::endl;

}

int main() {
    storeTest();
    return 0;
}
