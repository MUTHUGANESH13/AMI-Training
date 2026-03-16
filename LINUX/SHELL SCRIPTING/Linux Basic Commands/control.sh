#!/bin/bash

FILE=$1

[ -f "$FILE" ] && echo "File exists." || echo "File does not exist."
