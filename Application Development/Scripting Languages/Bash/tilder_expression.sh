#! /usr/bin/bash

echo $PWD

echo $OLDPWD

# ~ is same as $HOME
# ~+ is same as $PWD
# ~- is same as $OLDPWD

cd ~- # To switch back to previous working directory
echo ~-
cd ~+ # To switch back to current working directory
echo ~-
