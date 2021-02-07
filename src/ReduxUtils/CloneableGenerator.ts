import * as fs from "fs";
import {ClassDescriptor} from "./common";

export class CloneableGenerator {

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
#include "${descriptor.name}.h"

${descriptor.name} ${descriptor.name}::clone() {
    ${descriptor.name} cloned = ${descriptor.name}();
    
    ${descriptor.attributes.map(attribute => {
        return `cloned.${attribute.name} = this->${attribute.name};\n`
    })}
    
    return cloned;
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
#ifndef ${descriptor.name}_H
#define ${descriptor.name}_H
        
class ${descriptor.name} {
public:
${descriptor.attributes.map(attribute => {
    return `${attribute.type} ${attribute.name};`
}).join('\n')}

${descriptor.name} clone();
};

#endif
`

        const file = fs.writeFileSync(filename, generated)

    }

    public generate() : void
    {
        this.generateInterface();
        this.generateImplementation();
    }
}