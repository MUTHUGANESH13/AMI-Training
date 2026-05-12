#!/bin/bash

OUTPUT="system_info.txt"

echo "----- System Information -----" >> $OUTPUT
uname -a >> $OUTPUT 2>&1

echo "----- Network Information -----" >> $OUTPUT
ip a >> $OUTPUT 2>&1
