import * as fs from "fs";
import {
    ActionConfig,
    getGeneratedCaption,
    StoreConfig
} from "./common";

export class ActionGenerator {

    private readonly directory : string;
    private readonly storeConfig : StoreConfig;
    private readonly actionConfig : ActionConfig;

    constructor(directory : string, storeConfig : StoreConfig, actionConfig : ActionConfig) {
        this.actionConfig = actionConfig
        this.storeConfig = storeConfig
        this.directory = directory
    }

    private generateTypeBindings() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const actionConfig = this.actionConfig
        const filename = `${directory}/${actionConfig.action}.g.cpp`

        const generated = `
${getGeneratedCaption()}
#include "../ReduxStore.h"
#include "${actionConfig.action}.h"

std::string ${actionConfig.action}::getActionType() {
    return *knownActionTypes.find("${actionConfig.action}");
}
`

        const file = fs.writeFileSync(filename, generated)
    }

    private generateImplementation() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const actionConfig = this.actionConfig
        const filename = `${directory}/${actionConfig.action}.cpp`

        const generated = `
#include "${actionConfig.action}.h"
// TODO: implement action
`

        const file = fs.writeFileSync(filename, generated)
    }

    private generateInterface() : void
    {
        const directory = this.directory
        const storeConfig = this.storeConfig
        const actionConfig = this.actionConfig

        const filename = `${directory}/${actionConfig.action}.h`

        const generated = `
#ifndef ${actionConfig.action}_H
#define ${actionConfig.action}_H

#include "../Action.h"

class ${actionConfig.action} : public Action {
public:
    std::string getActionType() override;
    // TODO: action payload
};


#endif //${actionConfig.action}_H

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
