#!/bin/bash

echo "Enter first number:"
read a

echo "Enter second number:"
read b

echo "Enter operator (+ - * /):"
read op

case $op in
+) result=$((a+b))
   echo "Result = $result" ;;

-) result=$((a-b))
   echo "Result = $result" ;;

\*) result=$((a*b))
    echo "Result = $result" ;;

/) result=$((a/b))
   echo "Result = $result" ;;

*) echo "Invalid operator" ;;
esac
