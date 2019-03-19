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


#half finished code
# for destFile in $destFolder/*
# do 
#     #now delete files in tmp that aren't in the source any more
#     if [[ ! -f "$srcFile" && -f "$destFolder/$fileName" ]]; then
#         #file exists in tmp but not in source
#         echo "file shouldn't be here: $destFolder/$fileName , $srcFile"
#         #    rm -f $destFolder/$fileName
#     fi
# done
