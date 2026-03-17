/*
Program to perform basic arithmetic operations based on command-line arguments.
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : cal.c
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int a, b;

    if(argc != 4)
    {
        printf("Usage: %s operation num1 num2\n", argv[0]);
        return 1;
    }

    a = atoi(argv[2]);
    b = atoi(argv[3]);

    if(strcmp(argv[1], "add") == 0)
        printf("Result = %d\n", a + b);
    else if(strcmp(argv[1], "sub") == 0)
        printf("Result = %d\n", a - b);
    else if(strcmp(argv[1], "mul") == 0)
        printf("Result = %d\n", a * b);
    else
        printf("Invalid operation\n");

    return 0;
}