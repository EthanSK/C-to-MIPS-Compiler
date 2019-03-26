#!/bin/bash


compiler_test_dir="test/compiler"
cwd="$compiler_test_dir/src"
tests_dir="$compiler_test_dir/tests"
log_dir="$compiler_test_dir/log"


console_dump_file="$log_dir/console_dump.csv"


$cwd/runTests.sh >> $console_dump_file 2>&1