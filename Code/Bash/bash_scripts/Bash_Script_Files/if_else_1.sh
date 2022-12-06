#! /usr/bin/bash
ami=78

if (( $ami == 0 && $ami <5 ))
then
	echo "Ami kichu korte parbo na"
elif (( $ami > 5 || $ami <=500 ))
then
	echo "Ami sob parbo"
else
	echo "ami modon motra"
fi

