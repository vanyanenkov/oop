#include "GameField.h"
#include "ShipPlacementException.h"
#include "AttackOutOfBoundsException.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameField::GameField(int width, int height, AbilityManager& abilityManager)
    : width_(width), height_(height),
      grid_(width, std::vector<CellStatus>(height, CellStatus::Unknown)),
      shipManager_(),
      abilityManager_(abilityManager),
      doubleDamageActive_(false) {}

GameField::GameField(const GameField& other)
    : width_(other.width_), height_(other.height_),
      grid_(other.grid_), shipManager_(other.shipManager_),
      abilityManager_(other.abilityManager_),
      doubleDamageActive_(other.doubleDamageActive_) {}

GameField& GameField::operator=(const GameField& other) {
    if (this != &other) {
        width_ = other.width_;
        height_ = other.height_;
        grid_ = other.grid_;
        shipManager_ = other.shipManager_;
        doubleDamageActive_ = other.doubleDamageActive_;
        // abilityManager_ остается ссылкой на тот же объект
    }
    return *this;
}

GameField::GameField(GameField&& other) noexcept
    : width_(other.width_), height_(other.height_),
      grid_(std::move(other.grid_)), shipManager_(std::move(other.shipManager_)),
      abilityManager_(other.abilityManager_),
      doubleDamageActive_(other.doubleDamageActive_) {

    other.width_ = 0;
    other.height_ = 0;
    other.doubleDamageActive_ = false;
}

GameField& GameField::operator=(GameField&& other) noexcept {
    if (this != &other) {
        width_ = other.width_;
        height_ = other.height_;
        grid_ = std::move(other.grid_);
        shipManager_ = std::move(other.shipManager_);
        doubleDamageActive_ = other.doubleDamageActive_;
        // abilityManager_ остается ссылкой на тот же объект

        other.width_ = 0;
        other.height_ = 0;
        other.doubleDamageActive_ = false;
    }
    return *this;
}

void GameField::placeShip(Ship&& ship, int x, int y, Ship::Orientation orientation) {
    std::vector<std::pair<int, int>> positions;
    int dx = (orientation == Ship::Orientation::Horizontal) ? 1 : 0;
    int dy = (orientation == Ship::Orientation::Vertical) ? 1 : 0;

    for (int i = 0; i < ship.getLength(); ++i) {
        int nx = x + dx * i;
        int ny = y + dy * i;

        if (nx < 0 || nx >= width_ || ny < 0 || ny >= height_) {
            throw ShipPlacementException();
        }

        if (grid_[nx][ny] != CellStatus::Unknown) {
            throw ShipPlacementException();
        }

        positions.emplace_back(nx, ny);
    }

    for (const auto& pos : positions) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = pos.first + i;
                int ny = pos.second + j;
                if (nx >= 0 && nx < width_ && ny >= 0 && ny < height_) {
                    if (grid_[nx][ny] == CellStatus::Ship && !(nx == pos.first && ny == pos.second)) {
                        throw ShipPlacementException();
                    }
                }
            }
        }
    }

    for (const auto& pos : positions) {
        grid_[pos.first][pos.second] = CellStatus::Ship;
    }

    shipManager_.addShip(std::move(ship), positions);
}

void GameField::attackCell(int x, int y) {
    if (x < 0 || x >= width_ || y < 0 || y >= height_) {
        throw AttackOutOfBoundsException();
    }

    CellStatus& cell = grid_[x][y];

    if (cell == CellStatus::Ship || cell == CellStatus::Hit) {
        // Проверяем состояние сегмента
        Ship::SegmentState segmentState = shipManager_.getSegmentStateAt(x, y);

        if (segmentState == Ship::SegmentState::Destroyed) {
            std::cout << "Эта клетка уже была атакована." << std::endl;
            return;
        }

        int damage = doubleDamageActive_ ? 2 : 1;
        doubleDamageActive_ = false;

        shipManager_.attackShip(x, y, damage);
        segmentState = shipManager_.getSegmentStateAt(x, y);

        if (segmentState == Ship::SegmentState::Damaged) {
            std::cout << "Сегмент поврежден!" << std::endl;
        } else if (segmentState == Ship::SegmentState::Destroyed) {
            std::cout << "Сегмент уничтожен!" << std::endl;
            if (shipManager_.isShipSunkAt(x, y)) {
                std::cout << "Вы потопили корабль!" << std::endl;
                abilityManager_.addRandomAbility(); // Добавляем способность
            }
        }

        // Обновляем статус клетки
        cell = CellStatus::Hit;
    } else if (cell == CellStatus::Unknown) {
        std::cout << "Мимо!" << std::endl;
        cell = CellStatus::Empty;
    } else {
        std::cout << "Эта клетка уже была атакована." << std::endl;
    }
}

void GameField::setDoubleDamageActive(bool active) {
    doubleDamageActive_ = active;
}

bool GameField::scanArea(int x, int y) {
    if (x < 0 || x >= width_ - 1 || y < 0 || y >= height_ - 1) {
        return false;
    }
    for (int i = x; i < x + 2; ++i) {
        for (int j = y; j < y + 2; ++j) {
            if (grid_[i][j] == CellStatus::Ship || grid_[i][j] == CellStatus::Hit) {
                std::cout << "Сканер обнаружил сегмент корабля в области." << std::endl;
                return true;
            }
        }
    }
    std::cout << "В области нет сегментов кораблей." << std::endl;
    return true;
}

void GameField::randomBombardment() {
    shipManager_.randomAttack();
}

bool GameField::allShipsDestroyed() const {
    return shipManager_.allShipsDestroyed();
}

void GameField::initializeShipManager(int numShips, const std::vector<int>& shipSizes) {
    shipManager_ = ShipManager(numShips, shipSizes);
}
