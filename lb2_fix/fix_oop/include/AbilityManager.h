#ifndef ABILITYMANAGER_H
#define ABILITYMANAGER_H

#include <vector>
#include <memory>
#include "Ability.h"

class AbilityManager {
public:
    enum class AbilityType { DoubleDamage, Scanner, Bombardment };

    AbilityManager();
    void addRandomAbility();
    void useAbility(GameField& gameField);
    bool hasAbilities() const;
    AbilityType getNextAbilityType() const; 

private:
    void generateRandomAbility();
    std::vector<std::pair<AbilityType, std::unique_ptr<Ability>>> abilities_;
};

#endif 
