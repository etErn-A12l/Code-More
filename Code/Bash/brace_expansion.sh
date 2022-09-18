#! /usr/bin/bash

echo {jan,feb,mar,apr,may,jun}

echo { jan,feb,mar} # Spaces won't work

echo {a..z} # Prints a to z

echo {1..20} # Prints 1 to 20

echo month{01..10} # month01 month02.... month10

mkdir month{01..10} # Creates 10 folder of those names

touch month{01..10}/day{01..10}.txt # Creates 10 text file in each month directory

rm -r month{01..10}/ # Removes the created Directories


