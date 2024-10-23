#include "AbilityManager.h"
#include "DoubleDamage.h"
#include "Scanner.h"
#include "Bombardment.h"
#include "NoAbilitiesException.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <random>

AbilityManager::AbilityManager() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::vector<std::unique_ptr<Ability>> initialAbilities;
    initialAbilities.emplace_back(std::make_unique<DoubleDamage>());
    initialAbilities.emplace_back(std::make_unique<Scanner>());
    initialAbilities.emplace_back(std::make_unique<Bombardment>());

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(initialAbilities.begin(), initialAbilities.end(), g);

    for (auto& ability : initialAbilities) {
        if (dynamic_cast<DoubleDamage*>(ability.get())) {
            std::cout << "Получена способность 'Двойной урон'!" << std::endl;
        } else if (dynamic_cast<Scanner*>(ability.get())) {
            std::cout << "Получена способность 'Сканер'!" << std::endl;
        } else if (dynamic_cast<Bombardment*>(ability.get())) {
            std::cout << "Получена способность 'Обстрел'!" << std::endl;
        }
        abilities_.emplace(std::move(ability));
    }
}

void AbilityManager::generateRandomAbility() {
    int abilityType = std::rand() % 3;
    switch (abilityType) {
        case 0:
            abilities_.emplace(std::make_unique<DoubleDamage>());
            std::cout << "Получена способность 'Двойной урон'!" << std::endl;
            break;
        case 1:
            abilities_.emplace(std::make_unique<Scanner>());
            std::cout << "Получена способность 'Сканер'!" << std::endl;
            break;
        case 2:
            abilities_.emplace(std::make_unique<Bombardment>());
            std::cout << "Получена способность 'Обстрел'!" << std::endl;
            break;
    }
}

void AbilityManager::addRandomAbility() {
    generateRandomAbility();
}

void AbilityManager::useAbility(GameField& gameField) {
    if (abilities_.empty()) {
        throw NoAbilitiesException();
    }

    abilities_.front()->use(gameField);
    abilities_.pop();
}

bool AbilityManager::hasAbilities() const {
    return !abilities_.empty();
}
