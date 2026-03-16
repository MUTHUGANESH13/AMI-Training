#!/bin/bash

echo "Enter traffic light color (red/yellow/green):"
read color

case $color in
red)
    echo "Stop"
    ;;

yellow)
    echo "Get Ready"
    ;;

green)
    echo "Go"
    ;;

*)
    echo "Invalid input"
    ;;
esac
