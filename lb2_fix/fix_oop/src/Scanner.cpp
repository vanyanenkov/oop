#include "Scanner.h"
#include "GameField.h"

void Scanner::use([[maybe_unused]] GameField& gameField) {
    //Убраны выводы
}

Ability* Scanner::clone() const {
    return new Scanner(*this);
}