import * as fs from "fs";
import {
    ReducerConfig,
    getGeneratedCaption,
    StoreConfig
} from "./common";

export class ReducerGenerator {

    private readonly directory : string;
    private readonly storeConfig : StoreConfig;
    private readonly reducerConfig : ReducerConfig;

    constructor(directory : string, storeConfig : StoreConfig, reducerConfig : ReducerConfig) {
        this.reducerConfig = reducerConfig
        this.storeConfig = storeConfig
        this.directory = directory
    }

    private generateTypeBindings() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const reducerConfig = this.reducerConfig
        const filename = `${directory}/${reducerConfig.reducer}.g.cpp`

        const generated = `
${getGeneratedCaption()}
#include "${reducerConfig.reducer}.h"
#include "../ReduxStore.h"

std::string ${reducerConfig.reducer}::getReducerType() {
    //todo: add check
    return *knownReducerTypes.find("${reducerConfig.reducer}");
}

std::string ${reducerConfig.reducer}::getActionType() {
    //todo: add check
    return *knownActionTypes.find("${reducerConfig.action}");
}

void ${reducerConfig.reducer}::prepare(std::shared_ptr<State> state, std::shared_ptr<${reducerConfig.action}> action) {
    this->state = state;
    this->action = action;
}
`

        const file = fs.writeFileSync(filename, generated)
    }

    private generateImplementation() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const reducerConfig = this.reducerConfig
        const filename = `${directory}/${reducerConfig.reducer}.cpp`

        const generated = `
#include "${reducerConfig.reducer}.h"

std::shared_ptr<State> ${reducerConfig.reducer}::reduce() {
    StateBuilder builder = StateBuilder();
    builder.setState(*this->state);
    
    // TODO: implement reducer
    
    builder.build();

    return std::make_shared<State>(builder.getState());
}
`

        const file = fs.writeFileSync(filename, generated)
    }

    private generateInterface() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const reducerConfig = this.reducerConfig

        const filename = `${directory}/${reducerConfig.reducer}.h`

        const generated = `
#ifndef ${reducerConfig.reducer}_H
#define ${reducerConfig.reducer}_H


#include <memory>
#include "../actions/${reducerConfig.action}.h"
#include "../Reducer.h"

class ${reducerConfig.reducer} : public virtual Reducer {
private:
    std::shared_ptr<State> state;
    std::shared_ptr<${reducerConfig.action}> action;
public:
    ${reducerConfig.reducer}() = default;
    void prepare(std::shared_ptr<State> state, std::shared_ptr<${reducerConfig.action}> action);
    std::shared_ptr<State> reduce() override;
    std::string getActionType() override;
    std::string getReducerType() override;
};


#endif //${reducerConfig.reducer}_H

`

        const file = fs.writeFileSync(filename, generated)

    }

    public generate() : void
    {
        this.generateInterface();
        this.generateImplementation();
        this.generateTypeBindings();
    }

}
