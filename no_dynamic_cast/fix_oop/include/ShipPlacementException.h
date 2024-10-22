#ifndef SHIPPLACEMENTEXCEPTION_H
#define SHIPPLACEMENTEXCEPTION_H

#include "GameException.h"

class ShipPlacementException : public GameException {
public:
    ShipPlacementException();
    virtual ~ShipPlacementException() noexcept; // Добавлен виртуальный деструктор
};

#endif // SHIPPLACEMENTEXCEPTION_H
