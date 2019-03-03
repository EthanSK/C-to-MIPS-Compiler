#!/bin/bash
testProgPath=$1

# clang -cc1 -ast-view $testProgPath #-cc1 has problems with includes https://clang.llvm.org/docs/FAQ.html#id2

# gcc $testProgPath -fdump-tree-all-graph
# gcc -fdump-tree-vcg -g $testProgPath 
clang -Xclang -ast-dump  $testProgPath #works

# clang -cc1 -ast-print $testProgPath
