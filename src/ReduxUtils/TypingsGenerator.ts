import * as fs from "fs";
import {
    getGeneratedCaption,
    StoreConfig
} from "./common";

export class TypingsGenerator {

    private readonly directory : string;
    private readonly storeConfig : StoreConfig;

    constructor(directory : string, storeConfig : StoreConfig) {
        this.storeConfig = storeConfig
        this.directory = directory
    }

    private generateTypings() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const filename = `${directory}/ReduxStore.g.cpp`

        const generated = `
${getGeneratedCaption()}

${storeConfig.reducers.map(reducer => {
    return `#include "reducers/${reducer.reducer}.h"`
}).join('\n')}
${storeConfig.actions.map(action => {
    return `#include "actions/${action.action}.h"`
}).join('\n')}
#include "ReduxStore.h"

void initializeReducerTypes()
{
    knownReducerTypes = std::set<std::string>();
    ${storeConfig.reducers.map(reducer => {
        return `knownReducerTypes.insert("${reducer.reducer}");`
    }).join('\n')}
}

void initializeActionTypes()
{
    knownActionTypes = std::set<std::string>();
    ${storeConfig.actions.map(action => {
        return `knownActionTypes.insert("${action.action}");`
    }).join('\n')}
}

//Preparers
${storeConfig.reducers.map(reducer => {
    return `
void prepare${reducer.reducer}(ReduxStore *store, std::shared_ptr<Reducer> reducer, std::shared_ptr<Action> action)
{
    std::shared_ptr<${reducer.action}> targetAction = std::static_pointer_cast<${reducer.action}>(action);
    std::shared_ptr<${reducer.reducer}> targetReducer = std::dynamic_pointer_cast<${reducer.reducer}>(reducer);
    targetReducer->prepare(store->state, targetAction);
}    
`
}).join('\n')}

void initializeReducers(ReduxStore* store)
{
    store->preparers = std::map<std::string, void (*)(ReduxStore *store, std::shared_ptr<Reducer> reducer, std::shared_ptr<Action> action)>();
    store->reducers = std::list<std::shared_ptr<Reducer>>();
    
    ${storeConfig.reducers.map(reducer => {
        return `
    store->preparers["${reducer.reducer}"] = ${'&prepare' + reducer.reducer};
    store->reducers.push_back(std::make_shared<${reducer.reducer}>());
`
    }).join('\n')}
    
}
`

        const file = fs.writeFileSync(filename, generated)
    }

    public generate() : void
    {
        this.generateTypings();
    }

}
