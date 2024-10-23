#include "DoubleDamage.h"
#include "GameField.h"
#include <iostream>

void DoubleDamage::use(GameField& gameField) {
    gameField.setDoubleDamageActive(true);
    std::cout << "Способность 'Двойной урон' активирована для следующей атаки." << std::endl;
}
