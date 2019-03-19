#!/bin/bash
#run from project root
compiler_test_dir="test/compiler"
cwd="$compiler_test_dir/src"
test_cases_dir="$compiler_test_dir/testCases"
c_compiler="mips-linux-gnu-gcc " #replace this with our compiler

$cwd/moveTests.sh #so we can run tests from final dir for security


for c_file in ${test_cases_dir}/*.c ; do
    base=$(echo $c_file | sed -E -e "s|${test_cases_dir}/([^.]+)[.]c|\1|g");
    asm_file=$base.s
    driver_file="${base_driver}_driver.c"
    obj_file=$base.o
    binary_out=$base

    $c_compiler -S $c_file -o $asm_file
    mips-linux-gnu-gcc -mfp32 -o $obj_file -c $asm_file
    mips-linux-gnu-gcc -mfp32 -static -o $binary_out $obj_file $driver_file
    qemu-mips $binary_out

    exit_code=$?
    echo "exit code: $exit_code"
done