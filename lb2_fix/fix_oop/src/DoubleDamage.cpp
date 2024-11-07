#include "DoubleDamage.h"
#include "GameField.h"

void DoubleDamage::use(GameField& gameField) {
    gameField.setDoubleDamageActive(true);
    // Убраны выводы
}

Ability* DoubleDamage::clone() const {
    return new DoubleDamage(*this);
}
