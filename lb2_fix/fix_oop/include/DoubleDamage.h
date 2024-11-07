#ifndef DOUBLEDAMAGE_H
#define DOUBLEDAMAGE_H

#include "Ability.h"

class DoubleDamage : public Ability {
public:
    void use(GameField& gameField) override;
    Ability* clone() const override; 
};

#endif 
