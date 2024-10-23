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
$(OBJ_DIR)/AbilityManager.o: $(SRC_DIR)/AbilityManager.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/AbilityManager.cpp -o $(OBJ_DIR)/AbilityManager.o

$(OBJ_DIR)/AttackOutOfBoundsException.o: $(SRC_DIR)/AttackOutOfBoundsException.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/AttackOutOfBoundsException.cpp -o $(OBJ_DIR)/AttackOutOfBoundsException.o

$(OBJ_DIR)/Bombardment.o: $(SRC_DIR)/Bombardment.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Bombardment.cpp -o $(OBJ_DIR)/Bombardment.o

$(OBJ_DIR)/DoubleDamage.o: $(SRC_DIR)/DoubleDamage.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/DoubleDamage.cpp -o $(OBJ_DIR)/DoubleDamage.o

$(OBJ_DIR)/Game.o: $(SRC_DIR)/Game.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Game.cpp -o $(OBJ_DIR)/Game.o

$(OBJ_DIR)/GameException.o: $(SRC_DIR)/GameException.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/GameException.cpp -o $(OBJ_DIR)/GameException.o

$(OBJ_DIR)/GameField.o: $(SRC_DIR)/GameField.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/GameField.cpp -o $(OBJ_DIR)/GameField.o

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/NoAbilitiesException.o: $(SRC_DIR)/NoAbilitiesException.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/NoAbilitiesException.cpp -o $(OBJ_DIR)/NoAbilitiesException.o

$(OBJ_DIR)/Scanner.o: $(SRC_DIR)/Scanner.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Scanner.cpp -o $(OBJ_DIR)/Scanner.o

$(OBJ_DIR)/Ship.o: $(SRC_DIR)/Ship.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/Ship.cpp -o $(OBJ_DIR)/Ship.o

$(OBJ_DIR)/ShipManager.o: $(SRC_DIR)/ShipManager.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/ShipManager.cpp -o $(OBJ_DIR)/ShipManager.o

$(OBJ_DIR)/ShipPlacementException.o: $(SRC_DIR)/ShipPlacementException.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/ShipPlacementException.cpp -o $(OBJ_DIR)/ShipPlacementException.o

# Правило для очистки (удаление скомпилированных файлов)
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: clean
