#ifndef NOABILITIESEXCEPTION_H
#define NOABILITIESEXCEPTION_H

#include "GameException.h"

class NoAbilitiesException : public GameException {
public:
    NoAbilitiesException();
    virtual ~NoAbilitiesException() noexcept; // Добавлен виртуальный деструктор
};

#endif // NOABILITIESEXCEPTION_H
