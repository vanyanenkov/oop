#include "AttackOutOfBoundsException.h"

AttackOutOfBoundsException::AttackOutOfBoundsException()
    : GameException("Координаты атаки вне границ поля.") {}

AttackOutOfBoundsException::~AttackOutOfBoundsException() noexcept {} // Реализация деструктора
