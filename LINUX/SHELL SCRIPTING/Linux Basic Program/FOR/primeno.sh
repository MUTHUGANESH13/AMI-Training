#!/bin/bash

echo "Enter starting number (m):"
read m

echo "Enter ending number (n):"
read n

for ((i=m;i<=n;i++))
do
    echo $i
done
