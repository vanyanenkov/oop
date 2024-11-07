#include "Game.h"
#include <iostream>
#include <string>
#include <limits>
#include "NoAbilitiesException.h"
#include "AttackOutOfBoundsException.h"
#include "ShipPlacementException.h"

Game::Game()
    : abilityManager_(),
      gameField_(10, 10, abilityManager_),
      numShips_(0) {}

void Game::initialize() {
    std::cout << "Welcome to the Battleship game!" << std::endl;

    while (true) {
        std::cout << "Enter the number of ships: ";
        std::cin >> numShips_;
        if (std::cin.fail() || numShips_ <= 0) {
            std::cout << "Invalid input. The number of ships must be a positive integer!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    for (int i = 0; i < numShips_; ++i) {
        int length;
        while (true) {
            std::cout << "Enter the length of ship " << i + 1 << ": ";
            std::cin >> length;
            if (std::cin.fail() || length <= 0 || length > 4) {
                std::cout << "Invalid input. The length of the ship must be between 1 and 4!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                shipSizes_.push_back(length);
                break;
            }
        }
    }

    gameField_.initializeShipManager(numShips_, shipSizes_);
}

void Game::placeShips() {
    for (int i = 0; i < numShips_; ++i) {
        int x, y;
        char orientation;
        while (true) {
            std::cout << "Enter coordinates (x y) for ship of length " << shipSizes_[i] << ": ";
            std::cin >> x >> y;
            if (std::cin.fail() || x < 0 || x >= 10 || y < 0 || y >= 10) {
                std::cout << "Invalid coordinates. Coordinates must be integers within the range (0-9)!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "Enter orientation (h - horizontal, v - vertical): ";
            std::cin >> orientation;
            if (orientation != 'h' && orientation != 'v') {
                std::cout << "Invalid orientation. Must be 'h' for horizontal or 'v' for vertical!" << std::endl;
                continue;
            }

            try {
                Ship::Orientation dir = (orientation == 'h') ? Ship::Orientation::Horizontal : Ship::Orientation::Vertical;
                Ship ship(shipSizes_[i], dir);
                gameField_.placeShip(std::move(ship), x, y, dir);
                std::cout << "Ship placed successfully." << std::endl;
                break;
            } catch (const ShipPlacementException& e) {
                std::cout << e.what() << " Try again." << std::endl;
            }
        }
    }
}

void Game::gameLoop() {
    bool gameOver = false;
    std::string command;

    while (!gameOver) {
        std::cout << "Enter command (x y to attack, 'ability' to use the ability or 'exit' to quit): ";
        std::cin >> command;

        if (command == "exit") {
            std::cout << "Game exited." << std::endl;
            break;
        }

        if (command == "ability") {
            if (!abilityManager_.hasAbilities()) {
                std::cout << "Trying to use an ability when they are not there." << std::endl;
                continue;
            }

            try {
                AbilityManager::AbilityType abilityType = abilityManager_.getNextAbilityType();

                if (abilityType == AbilityManager::AbilityType::Scanner) {
                    int x, y;
                    while (true) {
                        std::cout << "Enter the coordinates of the upper left corner of the 2x2 area for angle (x y):";
                        std::cin >> x >> y;
                        if (std::cin.fail() || x < 0 || x >= 9 || y < 0 || y >= 9) {
                            std::cout << "Incorrect coordinates. Try again." << std::endl;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        break;
                    }
                    // Передаем координаты в GameField
                    bool found = gameField_.scanArea(x, y);
                    if (found) {
                        std::cout << "The scanner detected a ship segment in the area." << std::endl;
                    } else {
                        std::cout << "There are no ship segments in the area." << std::endl;
                    }
                    // Используем способность
                    abilityManager_.useAbility(gameField_);
                } else if (abilityType == AbilityManager::AbilityType::DoubleDamage) {
                    abilityManager_.useAbility(gameField_);
                    std::cout << "The 'Double Damage' ability is activated for the next attack." << std::endl;
                } else if (abilityType == AbilityManager::AbilityType::Bombardment) {
                    abilityManager_.useAbility(gameField_);
                    std::cout << "A random segment of the ship was fired upon." << std::endl;
                }
            } catch (const NoAbilitiesException& e) {
                std::cout << e.what() << std::endl;
            }

            // Проверяем окончание игры после применения способности
            if (gameField_.allShipsDestroyed()) {
                std::cout << "All ships are destroyed! Game over." << std::endl;
                gameOver = true;
            }
            continue;
        }

        int x, y;
        try {
            x = std::stoi(command);
            if (!(std::cin >> y)) {
                throw std::invalid_argument("Invalid input");
            }

            try {
                gameField_.attackCell(x, y);

                if (gameField_.allShipsDestroyed()) {
                    std::cout << "All ships are destroyed! Game over." << std::endl;
                    gameOver = true;
                }
            } catch (const AttackOutOfBoundsException& e) {
                std::cout << e.what() << std::endl;
            }
        } catch (std::exception&) {
            std::cout << "Invalid input. Please enter numeric values for coordinates or 'exit' to quit." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
    }
}

void Game::run() {
    initialize();
    placeShips();
    gameLoop();
}
