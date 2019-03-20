#!/bin/bash

#Info:
#run from project root
#⚠️DO NOT add rm test_deliverable/test_cases in case user mistakenly adds tests there (so can be recovered and moved later)⚠️
#should recursively test all folders in tests_dir
#this script calls another script that copies over the deliverable tests to the correct required directory (for ease)

#===========================================BOILERPLATE=================================================

#directories
compiler_test_dir="test/compiler"
cwd="$compiler_test_dir/src"
tests_dir="$compiler_test_dir/tests"
deliverable_test_cases_dir="test_deliverable/test_cases"
output_dir="$compiler_test_dir/output"
log_dir="$compiler_test_dir/log"


#files
summary_file="$log_dir/_summary.csv"
c_files=$(find $tests_dir -name "*.c")

#tools
c_compiler="mips-linux-gnu-gcc" #replace this with our compiler
if [[ "$1" != "" ]] ; then
    c_compiler="$1" #so we can pass in our compiler
fi
echo $c_compiler
gcc_flags_enforce_c90=" -std=c90 -ansi -pedantic "

#flags
is_verbose=1


#setup
rm -rf $output_dir
rm -f $summary_file #must remove otherwise causes problems 
mkdir -p $output_dir
mkdir -p $log_dir
$cwd/copyDeliverableTests.sh #so we can run tests from final dir for security


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



#============================================FUNCTIONALITY================================================


#run test
for c_file in $c_files ; do #use tests_dir here to enforce correctly added tests only
    [[ $c_file == *_driver.c ]] && continue #ignore the driver files
    rel_name_noext=$(echo $c_file | sed -E -e "s|${tests_dir}/([^.]+)[.]c|\1|g"); #relative (to tests_dir) name w/out extension
    parent_dir_rel=$(dirname "${rel_name_noext}") #eg deliverable
    driver_file="$tests_dir/${rel_name_noext}_driver.c" #but here use deliverable_test_cases to enforce file loc
    asm_file=$output_dir/$rel_name_noext.s
    obj_file=$output_dir/$rel_name_noext.o
    binary_out=$output_dir/$rel_name_noext

    mkdir -p $output_dir/$parent_dir_rel
    
    if [[ $is_verbose == 1 ]] ; then
        printf "${yellow}\n\n========================== $rel_name_noext ==========================\n\n${no_colour}"
        printf "${purple}============= file info =============\n"
        echo "c_file: $c_file"; echo "rel_name_noext: $rel_name_noext";echo "parent_dir_rel: $parent_dir_rel"; echo "driver_file: $driver_file"; echo "asm_file: $asm_file"; echo "obj_file: $obj_file"; echo "binary_out: $binary_out"
        printf "======================================\n${no_colour}"
    fi
    
    $c_compiler -S $c_file -o $asm_file
    mips-linux-gnu-gcc -mfp32 $gcc_flags_enforce_c90 -o $obj_file -c $asm_file
    mips-linux-gnu-gcc -mfp32 $gcc_flags_enforce_c90 -static -o $binary_out $obj_file $driver_file
    qemu-mips $binary_out
    exit_code=$?
    
    if [[ $exit_code == 0 ]]; then
        outcome="Pass"
        colour=$green
    else
        outcome="Fail"
        colour=$red
    fi
    
    csv_line="$rel_name_noext, exit code: $exit_code, $outcome"
    echo $csv_line >> $summary_file
    
    if [[ $is_verbose == 1 ]] ; then
        printf "${cyan}\n============= results ===============\n${no_colour}"
        echo -e "${colour}$csv_line${no_colour}"
        printf "${cyan}=====================================\n${no_colour}"
    fi
    
done
printf "${blue}\n\n========================== SUMMARY ==========================\n\n${no_colour}"

#happens regardless of verbose, otherwise script would output nothing useful
cat $summary_file | column -t -s, | grep -E --color=auto 'Fail|$$'
