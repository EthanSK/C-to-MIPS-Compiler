CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter
CXX = g++

# Avoid warning about register being deprecated on C++17
CPPFLAGS += -Wno-deprecated-register

SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
TMP_DIR = $(BUILD_DIR)/tmp
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = bin

SRC_FILES = $(shell tools/filenamesForMakefile.sh $(SRC_DIR) $(TMP_DIR) cpp)
OBJ_FILES = $(patsubst $(TMP_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

COMPILER_NAME = c_compiler
COMPILER_OUT = $(BIN_DIR)/$(COMPILER_NAME)

bin/c_compiler: $(COMPILER_OUT)

pre_build : 
	chmod u+x tools/flattenSrcFiles.sh 
	tools/flattenSrcFiles.sh $(SRC_DIR) $(TMP_DIR) cpp
	tools/flattenSrcFiles.sh $(INC_DIR) $(TMP_DIR) hpp
	tools/flattenSrcFiles.sh $(SRC_DIR) $(TMP_DIR) flex
	tools/flattenSrcFiles.sh $(SRC_DIR) $(TMP_DIR) y

$(OBJ_FILES) : $(SRC_FILES) pre_build
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) -std=c++11 -c $< -o $@

$(COMPILER_OUT): $(OBJ_FILES) 
	mkdir -p $(BIN_DIR)
	$(CXX) $(CPPFLAGS) -o $@ $^

.PHONY : clean

clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o