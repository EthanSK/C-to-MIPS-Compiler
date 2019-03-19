#!/bin/bash
srcFolder=$1
destFolder=$2
fileExt=$3

srcFiles=$(find $srcFolder -name "*.$fileExt")
srcFileNames=()
mkdir -p "$destFolder"

echo "Flattening ${fileExt} files"
for srcFile in $srcFiles
do
    fileName=$(basename "$srcFile")
    srcFileNames+=("$fileName")
    rsync --update $srcFile "$destFolder/$fileName" 
done

echo "Cleansing old ${fileExt} files"
destFiles=$(find $destFolder -name "*.$fileExt")
for destFile in $destFiles
do
    fileName=$(basename "$destFile")
    if [[ ! " ${srcFileNames[@]} " =~ " ${fileName} " ]]; then
        if [[ ! $fileName == *".yy."* && ! $fileName == *".tab."* ]]; then
            echo "deleting $fileName"
            rm -f "$destFile"
        fi
    fi
done
