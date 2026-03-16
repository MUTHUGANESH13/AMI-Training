#!/bin/bash

echo "Enter a number:"
read n

flag=0

for ((i=2;i<n;i++))
do
    if [ $((n%i)) -eq 0 ]
    then
        flag=1
        break
    fi
done

if [ $flag -eq 0 ]
then
    echo "Prime number"
else
    echo "Not a prime number"
fi
