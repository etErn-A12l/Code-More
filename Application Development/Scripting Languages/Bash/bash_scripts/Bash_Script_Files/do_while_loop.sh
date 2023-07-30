#! /usr/bin/bash

dom=10

while [ $dom -lt 20 ]
do
	echo "While loop is running"
	dom=$(( dom+1 ))
done
