#!/bin/bash
# to be run from project root

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

have_compiler=0
if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Only checking C reference against python reference."
    have_compiler=1
fi

cwd="test/pythonTranslator"
input_dir="$cwd/tests"
output_dir="$cwd/output"
output_file="$output_dir/_summary.csv"

RED='\033[0;31m'
NC='\033[0m'

rm -f $output_file
rm -rf $output_dir
mkdir -p ${output_dir}

for c_file in ${input_dir}/*.c ; do
    base=$(echo $c_file | sed -E -e "s|${input_dir}/([^.]+)[.]c|\1|g");
    echo "base $base"
    # Compile the reference C version
    gcc -Wno-implicit-int $c_file -o $output_dir/$base
    
    # Run the reference C version
    $output_dir/$base
    ref_c_exit_code=$?
    
    # Run the reference python version
    python3 ${input_dir}/$base.py
    ref_py_exit_code=$?
    
    if [[ ${have_compiler} -eq 0 ]] ; then
        translated_python_file="${base}Got.py"
        # Create the DUT python version by invoking the compiler with translation flags
        $compiler --translate $c_file -o ${output_dir}/$translated_python_file > /dev/null 2>&1
        
        # Run the DUT python version
        python3 ${output_dir}/$translated_python_file
        got_py_exit_code=$?
    fi
    
    
    if [[ $ref_c_exit_code -ne $ref_py_exit_code ]] ; then
        result="$base, REF_FAIL, Expected ${ref_c_exit_code}, got ${ref_py_exit_code}" #something is wrong with the test
        echo -e "${RED}REF_FAIL${NC}"
        elif [[ ${have_compiler} -ne 0 ]] ; then
        result="$base, Fail, No C compiler/translator"
        elif [[ $ref_c_exit_code -ne $got_py_exit_code ]] ; then
        result="$base, Fail, Expected ${ref_c_exit_code}, got ${got_py_exit_code}" #something is wrong with our compiler
        echo -e "${RED}Fail${NC}"
    else
        result="$base, Pass"
    fi
    
    csv_line="$result"
    echo $csv_line >> $output_file
done

echo
echo "Results:"
cat $output_file | column -t -s, | grep -E --color=auto 'Fail|$$'
