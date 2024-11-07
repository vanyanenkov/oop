#include "Bombardment.h"
#include "GameField.h"

void Bombardment::use(GameField& gameField) {
    gameField.randomBombardment();
    // Убраны выводы
}

Ability* Bombardment::clone() const {
    return new Bombardment(*this);
}
