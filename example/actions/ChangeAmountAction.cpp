//
// Created by ulkenauer on 04.02.2021.
//

#include "ChangeAmountAction.h"

ChangeAmountAction::ChangeAmountAction(int amount) : amount(amount) {}

int ChangeAmountAction::getAmount() {
    return this->amount;
}