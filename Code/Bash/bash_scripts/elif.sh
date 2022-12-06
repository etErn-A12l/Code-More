#! /usr/bin/bash

read -p "Tor naki pachay ukun hoyeche ? (Y/N) : " ans

if [ $ans == 'Y' ]
then 
	echo "E babaaaaaa !"
elif [ $ans == "N" ]
then
	echo "Jah tahole ami vul sunlam !"
else
	echo "Reaction not found !"
fi
