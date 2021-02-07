export class AttributeDescriptor {
    constructor(name : string, type : string) {
        this.name = name
        this.type = type
    }

    public name : string;
    public type : string;
}

export class ClassDescriptor {
    constructor(name : string, attributes : AttributeDescriptor[]) {
        this.name = name
        this.attributes = attributes
    }

    public static fromObject(object : any) : ClassDescriptor
    {
        const attributes = object.attributes.map(attributeObject => {
            return new AttributeDescriptor(attributeObject.name, attributeObject.type)
        })

        return new ClassDescriptor(object.name, attributes)
    }

    public name : string;
    public attributes : AttributeDescriptor[];
}

export function getGeneratedCaption () : string {
    return `
/** 
 ** GENERATED FILE
 ** DO NOT EDIT
 **/
 `
}

export function getGeneratedPartStartCaption () : string {
    return `
/** 
 ** GENERATED PART
 ** DO NOT EDIT
 **/
 `
}

export function getGeneratedPartEndCaption () : string {
    return `
/** 
 ** GENERATED PART END
 **/
 `
}

export type ActionConfig = {
    action: string,
}

export type ReducerConfig = {
    reducer: string,
    action: string,
}

export type AttributeConfig = {
    name: string,
    type: string,
}

export type StateConfig = {
    name: string,
    attributes: AttributeConfig[]
}

export type StoreConfig = {
    state: StateConfig,
    actions: ActionConfig[],
    reducers: ReducerConfig[]
}