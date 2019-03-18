#inner makefile that gets called recursively

SRC_DIR = ./tmp
OBJ_DIR = ./obj
BIN_DIR = ./bin

COMPILER_NAME = c_compiler
COMPILER_OUT = $(BIN_DIR)/$(COMPILER_NAME)

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

FLEX_NAME_NO_EXT = c_lexer
FLEX_FILE = $(SRC_DIR)/$(FLEX_NAME_NO_EXT).flex
FLEX_TARGET = $(SRC_DIR)/$(FLEX_NAME_NO_EXT).yy.cpp
FLEX_TARGET_OBJ = $(OBJ_DIR)/$(FLEX_NAME_NO_EXT).yy.o

YACC_NAME_NO_EXT = c_parser
YACC_FILE = $(SRC_DIR)/$(YACC_NAME_NO_EXT).y
YACC_TARGET_CPP = $(SRC_DIR)/$(YACC_NAME_NO_EXT).tab.cpp
YACC_TARGET_HPP = $(SRC_DIR)/$(YACC_NAME_NO_EXT).tab.hpp
YACC_TARGET_OBJ = $(OBJ_DIR)/$(YACC_NAME_NO_EXT).tab.o

CXX = g++
STD = c++11
CXXFLAGS = -std=${STD} -Wall -MMD -O0 -g -mavx -Wno-deprecated-register

compiler: $(COMPILER_OUT)

$(COMPILER_OUT): $(OBJ_FILES) $(FLEX_TARGET_OBJ) $(YACC_TARGET_OBJ)
	mkdir -p $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

$(YACC_TARGET_CPP) $(YACC_TARGET_HPP) : $(YACC_FILE)
	bison -v -d $(YACC_FILE) -o $(YACC_TARGET_CPP)

$(FLEX_TARGET) : $(FLEX_FILE) $(YACC_TARGET_HPP)
	flex -o $(FLEX_TARGET) $(FLEX_FILE)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)