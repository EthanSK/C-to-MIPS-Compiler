#!/bin/bash

cwd="devtools"
source_dir="test/compiler/tests/pythonTranslator/operators"
output_dir="test/compiler/tests/pythonTranslator/operators"

c_files=$(find $tests_dir -name "*.c")


for c_file in $c_files ; do #use tests_dir here to enforce correctly added tests only
    [[ $c_file == *_driver.c ]] && continue #ignore the driver files
    #cba to make bot
done