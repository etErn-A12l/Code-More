#! /bin/bash

if [ $# -eq 0 ]; then
    echo "Please Give Two File Names as Command Arguments !"
    exit 1
fi 

file_1=$1
file_2=$2

if cmp -s "$file_1" "$file_2"; then
    echo "Both Files Are Same, So Deleting 2nd File.."
    rm $file_2
    echo "Deleted $file_2"
else
    echo "Both Files are Different !"
fi