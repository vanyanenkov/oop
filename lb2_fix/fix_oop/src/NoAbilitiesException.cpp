#include "NoAbilitiesException.h"

NoAbilitiesException::NoAbilitiesException()
    : GameException("Trying to use an ability when they are not there.") {}
