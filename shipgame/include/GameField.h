#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <vector>
#include "ShipManager.h"

class GameField {
public:
    enum class CellStatus { Unknown, Empty, Ship, Hit };

    GameField(int width, int height, ShipManager& shipManager);
    bool placeShip(Ship&& ship, int x, int y, Ship::Orientation orientation);
    bool attackCell(int x, int y);

private:
    int width_, height_;
    std::vector<std::vector<CellStatus>> grid_;
    ShipManager& shipManager_;
};

#endif
