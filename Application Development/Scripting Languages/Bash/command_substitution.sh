#! /usr/bin/bash



# Syntax is $(command)

echo $(whoami)

time=$(date +%H:%m:%S)

echo "Hello ${USER}, the time is ${time}"
