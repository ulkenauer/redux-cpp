import * as fs from "fs";
import {ClassDescriptor, getGeneratedCaption} from "./common";

export class StateGenerator {

    private readonly directory : string;
    private readonly descriptor : ClassDescriptor;

    constructor(directory : string, descriptor : ClassDescriptor) {
        this.descriptor = descriptor
        this.directory = directory
    }

    private generateImplementation() : void
    {
        const directory = this.directory
        const descriptor = this.descriptor
        const filename = `${directory}/${descriptor.name}.cpp`

        const generated = `
${getGeneratedCaption()}
#include "${descriptor.name}.h"

${descriptor.name}::${descriptor.name}(${
            this.descriptor.attributes.map(attribute => {
                return `${attribute.type} ${attribute.name}`
            }).join(', ')
        }) : ${
            this.descriptor.attributes.map(attribute => {
                return `${attribute.name}(${attribute.name})`
            }).join(', ')
        } {}

void ${descriptor.name}Builder::setState(${descriptor.name} state) {
    
${
    this.descriptor.attributes.map(attribute => {
        return `\tthis->${attribute.name} = state.get${attribute.name.slice(0,1).toUpperCase() + attribute.name.slice(1)}();`
    }).join('\n')
}
}

${descriptor.name} ${descriptor.name}Builder::getState() {
    return this->state;
}

${
    this.descriptor.attributes.map(attribute => {
        return `
${attribute.type} ${this.descriptor.name}::get${attribute.name.slice(0,1).toUpperCase() + attribute.name.slice(1)}() const {
    return this->${attribute.name};
}`
    }).join('\n')
}


void ${descriptor.name}Builder::build() {
    this->state = ${descriptor.name}(${
        this.descriptor.attributes.map(attribute => {
            return `this->${attribute.name}`
        }).join(', ')
    });
}
`

        const file = fs.writeFileSync(filename, generated)
    }

    private generateInterface() : void
    {
        const directory = this.directory
        const descriptor = this.descriptor

        const filename = `${directory}/${descriptor.name}.h`

        const generated = `
${getGeneratedCaption()}
#ifndef ${descriptor.name}_H
#define ${descriptor.name}_H
#include <string>

class ${descriptor.name} {
public:
    ${descriptor.name}() = default;

    ${descriptor.name}(const ${descriptor.name} &state) = default;
    explicit ${descriptor.name}(${
        this.descriptor.attributes.map(attribute => {
            return `${attribute.type} ${attribute.name}`
        }).join(', ')
    });

${
    this.descriptor.attributes.map(attribute => {
        return `\t${attribute.type} get${attribute.name.slice(0,1).toUpperCase() + attribute.name.slice(1)}() const;`
    }).join('\n')
}

private:
${
    this.descriptor.attributes.map(attribute => {
        return `\t${attribute.type} ${attribute.name};`
    }).join('\n')
}
};

class ${descriptor.name}Builder {
public:
    ${descriptor.name}Builder() = default;
    void setState(${descriptor.name} state);
    ${descriptor.name} getState();

${
    this.descriptor.attributes.map(attribute => {
        return `\t${attribute.type} ${attribute.name};`
    }).join('\n')
}

    void build();
private:
     ${descriptor.name} state;
};

#endif //${descriptor.name}_H
`

        const file = fs.writeFileSync(filename, generated)

    }

    public generate() : void
    {
        this.generateInterface();
        this.generateImplementation();
    }
}