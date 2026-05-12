#!/bin/bash

echo "Enter first integer:"
read a

echo "Enter second integer:"
read b

if [ $((a % b)) -eq 0 ]
then
    echo "$a is a multiple of $b"
else
    echo "$a is NOT a multiple of $b"
fi
