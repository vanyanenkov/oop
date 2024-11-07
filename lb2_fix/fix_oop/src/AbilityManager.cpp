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

    std::vector<std::pair<AbilityType, std::unique_ptr<Ability>>> initialAbilities;
    initialAbilities.emplace_back(AbilityType::DoubleDamage, std::make_unique<DoubleDamage>());
    initialAbilities.emplace_back(AbilityType::Scanner, std::make_unique<Scanner>());
    initialAbilities.emplace_back(AbilityType::Bombardment, std::make_unique<Bombardment>());

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(initialAbilities.begin(), initialAbilities.end(), g);

    for (auto& abilityPair : initialAbilities) {
        AbilityType type = abilityPair.first;
        switch (type) {
            case AbilityType::DoubleDamage:
                std::cout << "Gained the ability 'Double damage'!" << std::endl;
                break;
            case AbilityType::Scanner:
                std::cout << "Gained the ability 'Scanner'!" << std::endl;
                break;
            case AbilityType::Bombardment:
                std::cout << "Gained the ability 'Bombing'!" << std::endl;
                break;
        }
        abilities_.emplace_back(type, std::move(abilityPair.second));
    }
}

void AbilityManager::generateRandomAbility() {
    int abilityType = std::rand() % 3;
    AbilityType type = static_cast<AbilityType>(abilityType);
    std::unique_ptr<Ability> newAbility;

    switch (type) {
        case AbilityType::DoubleDamage:
            newAbility = std::make_unique<DoubleDamage>();
            std::cout << "Gained the ability 'Double damage'!" << std::endl;
            break;
        case AbilityType::Scanner:
            newAbility = std::make_unique<Scanner>();
            std::cout << "Gained the ability 'Scanner'!" << std::endl;
            break;
        case AbilityType::Bombardment:
            newAbility = std::make_unique<Bombardment>();
            std::cout << "Gained the ability 'Bombing'!" << std::endl;
            break;
    }
    abilities_.emplace_back(type, std::move(newAbility));
}

void AbilityManager::addRandomAbility() {
    generateRandomAbility();
}

void AbilityManager::useAbility(GameField& gameField) {
    if (abilities_.empty()) {
        throw NoAbilitiesException();
    }

    abilities_.front().second->use(gameField);
    abilities_.erase(abilities_.begin());
}

bool AbilityManager::hasAbilities() const {
    return !abilities_.empty();
}

AbilityManager::AbilityType AbilityManager::getNextAbilityType() const {
    if (abilities_.empty()) {
        throw NoAbilitiesException();
    }
    return abilities_.front().first;
}
