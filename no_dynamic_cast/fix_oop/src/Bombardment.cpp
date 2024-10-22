#include "Bombardment.h"
#include "GameField.h"
#include <iostream>

void Bombardment::use(GameField& gameField) {
    gameField.randomBombardment();
    std::cout << "Произведен обстрел случайного сегмента корабля." << std::endl;
}

std::string Bombardment::getName() const {
    return "Обстрел";
}
