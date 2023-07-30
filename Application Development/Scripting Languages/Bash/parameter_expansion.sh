#! /usr/bin/bash

name="SreeJAn"

echo ${name} # Returns the original value

echo ${name,} # Returns the value after lowercasing the first letter

echo ${name,,} # Returns the whole value in lowercase

# My Username

echo $USER # All are in lowercase

echo ${USER^} # Returns the first letter as uppercase

echo ${USER^^} # Returns the whole value in upper case

echo ${#USER} ${#name} # Returns the length of the string

# String Slicing
# ******** Syntax ********

# ${parameter:offset:length}

var1="abcdefgh"

echo ${var1:0:5}
echo ${var1:2:7}

echo ${var1:1} # Stars from index 1 and goes till the end
echo ${var1:-4:2} # Starts from the last 4th character and goes forward till 2 length
