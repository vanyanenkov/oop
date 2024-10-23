#ifndef SCANNER_H
#define SCANNER_H

#include "Ability.h"

class Scanner : public Ability {
public:
    void use(GameField& gameField) override;
};

#endif // SCANNER_H
