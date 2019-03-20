#!/bin/bash


#Notes:
# make sure the python tests all pass first, and make sure that there are no ref errors

cwd="devtools"
python_tests_dir="test/pythonTranslator/tests"
compiler_tests_dir="test/compiler/tests"
c_files=$(find $python_tests_dir -name "*.c")


#Colours!!
no_colour='\033[0m'       # Colour Reset
black='\033[0;30m'        # Black
red='\033[0;31m'          # Red
green='\033[0;32m'        # Green
yellow='\033[0;33m'       # Yellow
blue='\033[0;34m'         # Blue
purple='\033[0;35m'       # Purple
cyan='\033[0;36m'         # Cyan
white='\033[0;37m'        # White


for c_file in $c_files ; do
    rel_name_noext=$(echo $c_file | sed -E -e "s|${tests_dir}/([^.]+)[.]c|\1|g"); #eg functions/funcA
    parent_dir_rel=$(dirname "${rel_name_noext}") #eg or functions/
    base_name_ext=$(basename "$c_file"); #eg funcA.c

    python3 ${python_tests_dir}/$rel_name_noext.py
    got_py_exit_code=$?


done