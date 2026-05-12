#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

product=$((a*b))

if [ $((product % 2)) -eq 0 ]
then
    echo "Product is Even"
else
    echo "Product is Odd"
fi
