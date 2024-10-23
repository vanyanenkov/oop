#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Ability.h"

class Bombardment : public Ability {
public:
    void use(GameField& gameField) override;
};

#endif // BOMBARDMENT_H
