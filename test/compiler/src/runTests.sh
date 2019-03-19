#!/bin/bash
#run from project root
compiler_test_dir="test/compiler"
cwd="$compiler_test_dir/src"
test_cases_dir="$compiler_test_dir/testCases"
build_dir="$compiler_test_dir/build"
bin_dir="$compiler_test_dir/bin"
c_compiler="mips-linux-gnu-gcc " #replace this with our compiler

rm -rf $build_dir
rm -rf $bin_dir
mkdir -p $build_dir
mkdir -p $bin_dir

$cwd/moveTests.sh #so we can run tests from final dir for security


for c_file in ${test_cases_dir}/*.c ; do
    [[ $c_file == *_driver.c ]] && continue #ignore the driver files
    base_name=$(echo $c_file | sed -E -e "s|${test_cases_dir}/([^.]+)[.]c|\1|g");
    driver_file="$test_cases_dir/${base_name}_driver.c"
    asm_file=$build_dir/$base_name.s
    obj_file=$build_dir/$base_name.o
    binary_out=$bin_dir/$base_name

    # echo $c_file
    # echo $base_name
    # echo $driver_file
    # echo $asm_file
    # echo $obj_file
    # echo $binary_out
    
    $c_compiler -S $c_file -o $asm_file
    mips-linux-gnu-gcc -mfp32 -o $obj_file -c $asm_file
    mips-linux-gnu-gcc -mfp32 -static -o $binary_out $obj_file $driver_file
    qemu-mips $binary_out
    
    exit_code=$?
    echo "exit code: $exit_code"
done