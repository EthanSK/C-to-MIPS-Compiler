SRC_DIR = src
INC_DIR = include
BIN_DIR = bin

COMPILER_NAME = c_compiler

TOOLS_DIR = tools
BUILD_DIR = build
TMP_DIR = $(BUILD_DIR)/tmp

FLATTEN_TOOL = ${TOOLS_DIR}/flattenSrcFiles.sh
MAKE_TOOL = ${TOOLS_DIR}/makefile

bin/c_compiler :
	chmod u+x ${FLATTEN_TOOL}
	${FLATTEN_TOOL} $(SRC_DIR) $(TMP_DIR) cpp
	${FLATTEN_TOOL} $(INC_DIR) $(TMP_DIR) hpp
	${FLATTEN_TOOL} $(SRC_DIR) $(TMP_DIR) flex
	${FLATTEN_TOOL} $(SRC_DIR) $(TMP_DIR) y
	cp -f ${MAKE_TOOL} ${BUILD_DIR}/makefile
	make -C ${BUILD_DIR} BIN_DIR=../${BIN_DIR} COMPILER_NAME=${COMPILER_NAME}

.PHONY : clean pre_build bin/c_compiler
clean :
	rm -rf $(BUILD_DIR)
	rm -rf $(BIN_DIR)
	rm -rf *.o