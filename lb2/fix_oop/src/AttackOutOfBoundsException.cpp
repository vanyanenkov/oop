#include "AttackOutOfBoundsException.h"

AttackOutOfBoundsException::AttackOutOfBoundsException()
    : GameException("Координаты атаки вне границ поля.") {}
