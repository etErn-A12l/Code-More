#!/usr/bin/bash

apple=$1

case $apple in
	"mazza")
		echo "I love mazza"
	"fruti")
		echo "I love fruti"
	"slice")
		echo "I love slice"
	* )
		echo "I don't love mango yet"
esac
