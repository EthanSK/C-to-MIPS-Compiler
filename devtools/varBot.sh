#!/bin/bash

cwd="devtools"
source_dir="test/pythonTranslator/tests/comparisons"
output_dir="test/pythonTranslator/tests/comparisons"
SED="sed"
overwrite_flag="-n" #overwiret flag -n means no overwrite
if [[ "$OSTYPE" == "darwin"* ]]; then
    SED="gsed"
fi

c_files=$(find $source_dir -name "*.c")
py_files=$(find $source_dir -name "*.py")


for c_file in $c_files ; do #use tests_dir here to enforce correctly added tests only
    # [[ $c_file == *_driver.c ]] && continue #ignore the driver files
    if [[ $c_file == *"var"* ]]; then
        continue
    fi
    base_name_ext=$(basename "$c_file"); #eg funcA.c
    base_name_noext=${base_name_ext%.*} #eg funcA
    out_file=$output_dir/"${base_name_noext}_var.c"
    cp -f $overwrite_flag $c_file $out_file #needn to be noext_driver.c
    if [[ $overwrite_flag != "-n" ]]; then
        $SED -i''  -e "s/{/{\n    int a = ;\n    int b = ;/g" $out_file
    fi
    
done

for py_file in $py_files ; do #use tests_dir here to enforce correctly added tests only
    # [[ $c_file == *_driver.c ]] && continue #ignore the driver files
    if [[ $py_file == *"var"* ]]; then
        continue
    fi
    base_name_ext=$(basename "$py_file"); #eg funcA.c
    base_name_noext=${base_name_ext%.*} #eg funcA
    out_file=$output_dir/"${base_name_noext}_var.py"
    cp -f $overwrite_flag $py_file $out_file #needn to be noext_driver.c
    if [[ $overwrite_flag != "-n" ]]; then
        $SED -i''  -e "s/):/):\n    a = \n    b = /g" $out_file
    fi
    
done