#!/bin/bash


c_compiler="mips-linux-gnu-gcc" #replace this with our compiler
gcc_flags="-mfp32 -std=c90 -ansi -pedantic"

cwd="playground/parser"
$c_compiler -S $cwd/test1.c -o $cwd/test1.s
$c_compiler -S $cwd/test2.c -o $cwd/test2.s
