#ifndef ABILITY_H
#define ABILITY_H

class GameField;

class Ability {
public:
    virtual ~Ability() = default;
    virtual void use(GameField& gameField) = 0;
};

#endif // ABILITY_H
