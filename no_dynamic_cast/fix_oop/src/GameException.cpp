#include "GameException.h"

GameException::GameException(const std::string& message)
    : message_(message) {}

GameException::~GameException() noexcept {} // Предоставлена реализация

const char* GameException::what() const noexcept {
    return message_.c_str();
}
