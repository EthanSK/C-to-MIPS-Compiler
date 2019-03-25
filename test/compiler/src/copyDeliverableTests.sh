#!/bin/bash
test_cases_in_dir="test/compiler/tests/deliverable"
test_cases_out_dir="test_deliverable/test_cases"
rm -rf $test_cases_out_dir
mkdir -p $test_cases_out_dir
cp -p -R $test_cases_in_dir/* $test_cases_out_dir