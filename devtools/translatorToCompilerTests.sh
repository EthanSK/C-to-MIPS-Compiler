#!/bin/bash


#Notes:
# this script implements the necessary changes between the python tester and compiler tester interfaces (eg making the exit code 0 meaning a pass for compiler tests)
# make sure the python tests all pass first, and make sure that there are no ref errors⚠️This script assumes the corresponding python is correct⚠️

cwd="devtools"
python_tests_dir="test/pythonTranslator/tests"
compiler_tests_dir="test/compiler/tests/fromPythonTranslator" #have under subfolder so we don't confuse manually created tests with  auto moved ones
c_files=$(find $python_tests_dir -name "*.c")
test_driver_template="$cwd/testDriverTemplate.txt"


new_main_name="MAIN_FUNCTION"



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
    base_name_noext=${base_name_ext%.*} #eg funcA
    target_c_file=$compiler_tests_dir/$rel_name_noext.c
    target_c_driver_file="$compiler_tests_dir/${rel_name_noext}_driver.c"

    mkdir -p  $compiler_tests_dir/$parent_dir_rel


    # find what the exit code should be
    python3 ${python_tests_dir}/$rel_name_noext.py
    exit_code_py=$?

    # copy over c file to compiler dir
    cp -f $c_file $target_c_file #should overwrite existing files

    #change the name of the main() function to $new_main_name
    sed -i '' -e "s/main/${new_main_name}_${base_name_noext}/g" $target_c_file #all functiosn need to be unique named if theyre gonna be declared in drivers

    #create driver file
    cp -f $test_driver_template $target_c_driver_file
    sed -i '' -e "s/FUNC_NAME/${new_main_name}_${base_name_noext}/g" $target_c_driver_file #add function name
    sed -i '' -e "s/FUNC_EXIT_CODE/$exit_code_py/g" $target_c_driver_file #add expected exit code

done