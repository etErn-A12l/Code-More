#! /usr/bin/bash

read -p "What is your age : " age

if [ $age -lt 18 ]
then
	echo "You are not eligible for hacking !"
fi
