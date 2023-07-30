#! /usr/bin/bash

echo "5/2" | bc # Ans=2, We have to set the scale variable

echo "scale=2; 5/2" | bc # Ans=2.50, as scale is set to two decimal places

echo "scale=10; 5/2" | bc # Similarly Ans=2.500000000
