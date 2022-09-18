#! /usr/bin/bash

echo $((2 + 4)) # 6

x=2
y=4

echo $(( $x + $y ))
echo $(( x + y )) #Does the same

echo $(( 4**2 )) # 4^2 = 16
