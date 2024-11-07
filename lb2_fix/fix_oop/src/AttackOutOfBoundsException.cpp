#include "AttackOutOfBoundsException.h"

AttackOutOfBoundsException::AttackOutOfBoundsException()
    : GameException("Attack coordinates outside the field boundaries.") {}
