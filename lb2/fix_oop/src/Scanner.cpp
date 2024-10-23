#include "Scanner.h"
#include "GameField.h"
#include <iostream>

void Scanner::use(GameField& gameField) {
    int x, y;
    std::cout << "Введите координаты левого верхнего угла области 2x2 для сканирования (x y): ";
    std::cin >> x >> y;

    if (!gameField.scanArea(x, y)) {
        std::cout << "Не удалось сканировать: координаты вне границ." << std::endl;
    }
}
