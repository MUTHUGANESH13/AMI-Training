#!/bin/bash

echo "Enter number of values:"
read n

sum=0

for ((i=1;i<=n;i++))
do
    echo "Enter number:"
    read num
    sum=$((sum+num))
done

avg=$((sum/n))

echo "Sum = $sum"
echo "Average = $avg"
