import * as ReduxUtils from "./ReduxUtils";
import * as fs from "fs";

function foobar() : void
{
    const storeConfig : ReduxUtils.StoreConfig = JSON.parse(fs.readFileSync('./example/StoreConfig.json').toString())
    const descriptor = ReduxUtils.ClassDescriptor.fromObject(storeConfig.state)

    const bootstrapStateStructure = () => {
        new ReduxUtils.StateGenerator(
            'generated',
            descriptor
        ).generate()
    }

    const bootstrapActionClasses = () => {
        storeConfig.actions.forEach(actionConfig => {
            new ReduxUtils.ActionGenerator(
                'generated/actions',
                storeConfig,
                actionConfig
            ).generate()
        })
    }

    const bootstrapReducerClasses = () => {
        storeConfig.reducers.forEach(reducerConfig => {
            new ReduxUtils.ReducerGenerator(
                'generated/reducers',
                storeConfig,
                reducerConfig
            ).generate()
        })
    }

    const generateTypings = () => {
        new ReduxUtils.TypingsGenerator(
            'generated',
            storeConfig
        ).generate()
    }

    bootstrapStateStructure()
    bootstrapActionClasses()
    bootstrapReducerClasses()
    generateTypings()

}

foobar()