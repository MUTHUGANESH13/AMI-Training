#!/bin/bash

echo "Enter how many numbers:"
read n

echo "Enter number:"
read num
small=$num
large=$num

for ((i=2;i<=n;i++))
do
    echo "Enter number:"
    read num

    if [ $num -lt $small ]
    then
        small=$num
    fi

    if [ $num -gt $large ]
    then
        large=$num
    fi
done

echo "Smallest number = $small"
echo "Largest number = $large"
