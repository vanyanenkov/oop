#include "NoAbilitiesException.h"

NoAbilitiesException::NoAbilitiesException()
    : GameException("Попытка применить способность, когда их нет.") {}

NoAbilitiesException::~NoAbilitiesException() noexcept {} // Реализация деструктора
