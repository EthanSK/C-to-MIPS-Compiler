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

pre_build : 
	chmod u+x tools/flattenSrcFiles.sh 
	tools/flattenSrcFiles.sh $(SRC_DIR) $(TMP_DIR) cpp
	tools/flattenSrcFiles.sh $(INC_DIR) $(TMP_DIR) hpp
	tools/flattenSrcFiles.sh $(SRC_DIR) $(TMP_DIR) flex
	tools/flattenSrcFiles.sh $(SRC_DIR) $(TMP_DIR) y

# build/%.o : src/%.cpp src/%.hpp
# 	mkdir -p build
# 	$(CXX) $(CPPFLAGS) -std=c++11 -c $< -o $@

# simulator: build/simulator.o build/helpers.o build/memory.o build/registers.o build/instructions.o  
# 	mkdir -p bin
# 	$(CXX) $(CPPFLAGS) -std=c++11 build/simulator.o build/helpers.o build/memory.o build/registers.o build/instructions.o -o bin/mips_simulator

# testbench: 
# 	mkdir -p bin
# 	rm -f bin/mips_testbench
# 	cp -a test/testbench.sh bin/mips_testbench
# 	chmod 755 bin/mips_testbench

clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o