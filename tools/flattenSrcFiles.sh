#!/bin/bash
srcFolder=$1
destFolder=$2
fileExt=$3

srcFiles=$(find $srcFolder -name "*.$fileExt")
mkdir -p "$destFolder"

for srcFile in $srcFiles
do
    fileName=$(basename "$srcFile")
    rsync --update $srcFile "$destFolder/$fileName"
done


