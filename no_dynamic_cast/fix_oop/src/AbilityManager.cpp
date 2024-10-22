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
        std::cout << "Получена способность '" << ability->getName() << "'!" << std::endl;
        abilities_.emplace(std::move(ability));
    }
}

void AbilityManager::generateRandomAbility() {
    int abilityType = std::rand() % 3;
    std::unique_ptr<Ability> newAbility;

    switch (abilityType) {
        case 0:
            newAbility = std::make_unique<DoubleDamage>();
            break;
        case 1:
            newAbility = std::make_unique<Scanner>();
            break;
        case 2:
            newAbility = std::make_unique<Bombardment>();
            break;
    }

    std::cout << "Получена способность '" << newAbility->getName() << "'!" << std::endl;
    abilities_.emplace(std::move(newAbility));
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
