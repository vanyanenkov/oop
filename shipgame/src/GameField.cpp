#include "GameField.h"
#include <iostream>

GameField::GameField(int width, int height, ShipManager& shipManager)
    : width_(width), height_(height),
      grid_(width, std::vector<CellStatus>(height, CellStatus::Unknown)),
      shipManager_(shipManager) {}

bool GameField::placeShip(Ship&& ship, int x, int y, Ship::Orientation orientation) {
    std::vector<std::pair<int, int>> positions;

    if (orientation == Ship::Orientation::Horizontal) {
        if (x + ship.getLength() > width_) return false;
        for (int i = 0; i < ship.getLength(); ++i) {
            if (grid_[x + i][y] != CellStatus::Unknown) return false;
            positions.emplace_back(x + i, y);
        }
    } else {
        if (y + ship.getLength() > height_) return false;
        for (int i = 0; i < ship.getLength(); ++i) {
            if (grid_[x][y + i] != CellStatus::Unknown) return false;
            positions.emplace_back(x, y + i);
        }
    }

    for (const auto& pos : positions) {
        grid_[pos.first][pos.second] = CellStatus::Ship;
    }

    shipManager_.addShip(std::move(ship), positions);
    return true;
}

bool GameField::attackCell(int x, int y) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        std::cout << "Invalid coordinates." << std::endl;
        return false;
    }

    CellStatus& cell = grid_[x][y];

    // Check if the cell contains a ship
    if (cell == CellStatus::Ship || cell == CellStatus::Hit) {
        bool segmentDestroyed = shipManager_.isShipSegmentDestroyed(x, y);
        bool segmentDamaged = shipManager_.isShipSegmentDamaged(x, y);

        if (segmentDestroyed) {
            std::cout << "This segment is already destroyed." << std::endl;
            return false;
        }

        shipManager_.attackShip(x, y);

        if (!segmentDamaged) {
            std::cout << "Hit!" << std::endl;
        } else {
            std::cout << "Segment destroyed!" << std::endl;
            if (shipManager_.isShipSunkAt(x, y)) {
                std::cout << "You sunk a ship!" << std::endl;
            }
        }

        
        cell = CellStatus::Hit;

        return true;
    }

    if (cell == CellStatus::Unknown) {
        std::cout << "Miss!" << std::endl;
        cell = CellStatus::Empty;
        return false;
    }

    if (cell == CellStatus::Empty) {
        std::cout << "This cell was already attacked." << std::endl;
        return false;
    }

    return false;
}
