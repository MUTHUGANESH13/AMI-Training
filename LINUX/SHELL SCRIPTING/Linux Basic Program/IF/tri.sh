#!/bin/bash

echo "Enter three sides:"
read a b c

if [ $((a*a + b*b)) -eq $((c*c)) ] || \
   [ $((a*a + c*c)) -eq $((b*b)) ] || \
   [ $((b*b + c*c)) -eq $((a*a)) ]
then
    echo "It is a Right Triangle"
else
    echo "It is NOT a Right Triangle"
fi
