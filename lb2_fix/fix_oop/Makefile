CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Указываем исходные и объектные файлы вручную
SRC_FILES = $(SRC_DIR)/AbilityManager.cpp $(SRC_DIR)/AttackOutOfBoundsException.cpp \
            $(SRC_DIR)/Bombardment.cpp $(SRC_DIR)/DoubleDamage.cpp $(SRC_DIR)/Game.cpp \
            $(SRC_DIR)/GameException.cpp $(SRC_DIR)/GameField.cpp $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/NoAbilitiesException.cpp $(SRC_DIR)/Scanner.cpp \
            $(SRC_DIR)/Ship.cpp $(SRC_DIR)/ShipManager.cpp $(SRC_DIR)/ShipPlacementException.cpp

OBJ_FILES = $(OBJ_DIR)/AbilityManager.o $(OBJ_DIR)/AttackOutOfBoundsException.o \
            $(OBJ_DIR)/Bombardment.o $(OBJ_DIR)/DoubleDamage.o $(OBJ_DIR)/Game.o \
            $(OBJ_DIR)/GameException.o $(OBJ_DIR)/GameField.o $(OBJ_DIR)/main.o \
            $(OBJ_DIR)/NoAbilitiesException.o $(OBJ_DIR)/Scanner.o $(OBJ_DIR)/Ship.o \
            $(OBJ_DIR)/ShipManager.o $(OBJ_DIR)/ShipPlacementException.o

TARGET = $(BIN_DIR)/game

all: $(TARGET)

# Правило сборки конечного исполняемого файла
$(TARGET): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_FILES)

# Правила компиляции для каждого .cpp файла в .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Правило для очистки (удаление скомпилированных файлов)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
