#!/bin/bash
# to be run from project root



#===========================================BOILERPLATE=================================================

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

python_tests_dir="test/pythonTranslator"
cwd="$python_tests_dir/src"
tests_dir="$python_tests_dir/tests"
output_dir="$python_tests_dir/output"
log_dir="$python_tests_dir/log"
summary_file="$log_dir/_summary.csv"


c_files=$(find $tests_dir -name "*.c")


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

rm -f $summary_file #must remove summary file
rm -rf $output_dir
mkdir -p ${output_dir}
mkdir -p $log_dir



#============================================FUNCTIONALITY================================================


for c_file in $c_files ; do
    rel_name_noext=$(echo $c_file | sed -E -e "s|${tests_dir}/([^.]+)[.]c|\1|g"); #eg functions/funcA
    parent_dir_rel=$(dirname "${rel_name_noext}") #eg or functions/
    base_name_ext=$(basename "$c_file"); #eg funcA.c
    # base_name_noext=${base_name_ext%.*} #not using this any more, being more legit
    
    mkdir -p $output_dir/$parent_dir_rel
    
    echo "test: $rel_name_noext"
    # Compile the reference C version
    gcc -Wno-implicit-int $c_file -o $output_dir/$rel_name_noext
    
    # Run the reference C version
    $output_dir/$rel_name_noext
    ref_c_exit_code=$?
    
    # Run the reference python version
    python3 ${tests_dir}/$rel_name_noext.py
    ref_py_exit_code=$?
    
    if [[ ${have_compiler} -eq 0 ]] ; then
        translated_python_file="${output_dir}/${rel_name_noext}_result.py"
        # Create the DUT python version by invoking the compiler with translation flags
        $compiler --translate $c_file -o $translated_python_file > /dev/null 2>&1
        
        # Run the DUT python version
        python3 $translated_python_file
        got_py_exit_code=$?
    fi
    
    
    if [[ $ref_c_exit_code -ne $ref_py_exit_code ]] ; then
        result="$rel_name_noext, REF_FAIL, Expected ${ref_c_exit_code}, got ${ref_py_exit_code}" #something is wrong with the test
        echo -e "${red}REF_FAIL${no_colour}"
        elif [[ ${have_compiler} -ne 0 ]] ; then
        result="${red}$rel_name_noext, Fail, No C compiler/translator${no_colour}"
        elif [[ $ref_c_exit_code -ne $got_py_exit_code ]] ; then
        result="$rel_name_noext, Fail, Expected ${ref_c_exit_code}, got ${got_py_exit_code}" #something is wrong with our compiler
        echo -e "${red}Fail${no_colour}"
        res_colour=$red
    else
        result="$rel_name_noext, Pass" #must keep rel name noext here coz goes in csv
        res_colour=$green
    fi
    
    csv_line="$result"
    echo -e "${res_colour}result: $csv_line${no_colour}"
    echo -e "${yellow}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~${no_colour}"
    echo $csv_line >> $summary_file
done

echo
printf "${cyan}\n\n========================== SUMMARY ==========================\n\n${no_colour}"
cat $summary_file | column -t -s, | grep -E --color=auto 'Fail|$$'
