#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

class GameException : public std::exception {
public:
    explicit GameException(const std::string& message);
    virtual ~GameException() noexcept; // Добавлен виртуальный деструктор
    const char* what() const noexcept override;

private:
    std::string message_;
};

#endif // GAMEEXCEPTION_H
