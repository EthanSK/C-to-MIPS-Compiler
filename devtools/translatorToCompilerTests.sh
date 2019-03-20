#!/bin/bash


#Notes:
# this script implements the necessary changes between the python tester and compiler tester interfaces (eg making the exit code 0 meaning a pass for compiler tests)
# make sure the python tests all pass first, and make sure that there are no ref errors

cwd="devtools"
python_tests_dir="test/pythonTranslator/tests"
compiler_tests_dir="test/compiler/tests/fromPyTrans" #have under subfolder so we don't confuse manually created tests with  auto moved ones
c_files=$(find $python_tests_dir -name "*.c")

new_main_name="mainFUNCTION"



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
    rel_name_noext=$(echo $c_file | sed -E -e "s|${python_tests_dir}/([^.]+)[.]c|\1|g"); #eg functions/funcA
    parent_dir_rel=$(dirname "${rel_name_noext}") #eg or functions/
    base_name_ext=$(basename "$c_file"); #eg funcA.c

    mkdir -p  $compiler_tests_dir/$parent_dir_rel


    # find what the exit code should be
    python3 ${python_tests_dir}/$rel_name_noext.py
    exit_code_py=$?

    target_c_file=$compiler_tests_dir/$rel_name_noext.c
    # copy over c file to compiler dir
    cp -f $c_file $target_c_file #should overwrite existing files

    #change the name of the main() function to $new_main_name
    sed -i -e "s/main/$new_main_name/g" $target_c_file



done