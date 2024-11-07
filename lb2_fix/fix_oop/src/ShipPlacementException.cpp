#include "ShipPlacementException.h"

ShipPlacementException::ShipPlacementException()
    : GameException("Unable to place a ship: crossing or touching another ship.") {}
