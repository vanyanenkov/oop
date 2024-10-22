#include "ShipPlacementException.h"

ShipPlacementException::ShipPlacementException()
    : GameException("Невозможно разместить корабль: пересечение или соприкосновение с другим кораблем.") {}

ShipPlacementException::~ShipPlacementException() noexcept {} // Реализация деструктора