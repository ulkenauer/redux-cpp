//
// Created by ulkenauer on 27.02.2021.
//

#ifndef EXAMPLE_WRAPPEDACTION_H
#define EXAMPLE_WRAPPEDACTION_H


#include <memory>
#include "ActionMetadata.h"

// CLEAN EXTRACT

/**
 * Action with metadata
 */
class WrappedAction {
    public:
        ActionMetadata metadata;
        std::shared_ptr<void> action;
};


#endif //EXAMPLE_WRAPPEDACTION_H
