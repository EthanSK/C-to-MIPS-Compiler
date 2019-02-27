SRC_DIR = ./tmp
OBJ_DIR = ./obj
BIN_DIR = ./bin

COMPILER_NAME = c_compiler
COMPILER_OUT = $(BIN_DIR)/$(COMPILER_NAME)

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

CXX = g++
CXXFLAGS = -std=c++11 -Wall -MMD -O0 -g -mavx -Wno-deprecated-register

compiler: $(COMPILER_OUT)

$(COMPILER_OUT): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)