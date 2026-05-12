#!/bin/bash

echo "Enter length:"
read length

echo "Enter breadth:"
read breadth

perimeter=$((2*(length+breadth)))

echo "Perimeter of rectangle is $perimeter"
