#!/bin/bash

#Info:
#run from project root
#⚠️DO NOT rm test_deliverable/test_cases in case user mistakenly adds tests there (so can be recovered and moved later)⚠️



#===========================================BOILERPLATE=================================================

#directories
compiler_test_dir="test/compiler"
cwd="$compiler_test_dir/src"
test_cases_dir="$compiler_test_dir/testCases"
deliverable_test_cases_dir="test_deliverable/test_cases"
build_dir="$compiler_test_dir/build"
bin_dir="$compiler_test_dir/bin"
log_dir="$compiler_test_dir/log"


#files
summary_file="$log_dir/_summary.csv"


#tools
c_compiler="mips-linux-gnu-gcc" #replace this with our compiler


#flags
is_verbose=1


#setup
rm -rf $build_dir
rm -rf $bin_dir
rm -rf $log_dir
mkdir -p $build_dir
mkdir -p $bin_dir
mkdir -p $log_dir
$cwd/moveTests.sh #so we can run tests from final dir for security




#============================================FUNCTIONALITY================================================

#run test
for c_file in ${test_cases_dir}/*.c ; do #use test_cases_dir here to enforce correctly added tests only

    [[ $c_file == *_driver.c ]] && continue #ignore the driver files
    base_name=$(echo $c_file | sed -E -e "s|${test_cases_dir}/([^.]+)[.]c|\1|g");
    driver_file="$deliverable_test_cases_dir/${base_name}_driver.c" #but here use deliverable_test_cases to enforce file loc
    asm_file=$build_dir/$base_name.s
    obj_file=$build_dir/$base_name.o
    binary_out=$bin_dir/$base_name
    
    if [[ $is_verbose == 1 ]] ; then
        printf "\n============= file info =============\n"
        echo "c_file: $c_file"; echo "base_name: $base_name"; echo "driver_file: $driver_file"; echo "asm_file: $asm_file"; echo "obj_file: $obj_file"; echo "binary_out: $binary_out"
        printf "======================================\n\n"
    fi
    
    $c_compiler -S $c_file -o $asm_file
    mips-linux-gnu-gcc -mfp32 -o $obj_file -c $asm_file
    mips-linux-gnu-gcc -mfp32 -static -o $binary_out $obj_file $driver_file
    qemu-mips $binary_out
    exit_code=$?
    
    if [[ $exit_code == 0 ]]; then
        outcome="Pass"
    else
        outcome="Fail"
    fi
    
    csv_line="$base_name, exit code: $exit_code, $outcome"
    echo $csv_line >> $summary_file
    
    if [[ $is_verbose == 1 ]] ; then
        printf "\n============= results ==============\n"
        echo $csv_line
        printf "======================================\n\n"
    fi
    
done

#happens regardless of verbose, otherwise script would output nothing useful
cat $summary_file | column -t -s, | grep -E --color=auto 'Fail|$$'
