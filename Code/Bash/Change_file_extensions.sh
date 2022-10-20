#!/bin/bash
for f in *.$1
do
    [ -f "$f" ] && mv -v "$f" "${f%$1}$2"
done

# Example usage: 

# $ ./Change_filr_extensions.sh txt cpp

# it will change all txt files to cpp files