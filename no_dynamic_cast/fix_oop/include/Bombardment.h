#ifndef BOMBARDMENT_H
#define BOMBARDMENT_H

#include "Ability.h"

class Bombardment : public Ability {
public:
    void use(GameField& gameField) override;
    std::string getName() const override; // Добавили эту строку
};

#endif // BOMBARDMENT_H
