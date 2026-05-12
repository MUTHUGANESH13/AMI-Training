/*
Program to set and get environment variables in C.
Author   : MUTHUGANESH S
Date     : 07/02/2026
Filename : set.c
*/

//header files
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setenv("MY_VAR", "HelloEnvironment", 1);

    char *value = getenv("MY_VAR");

    if(value != NULL)
        printf("MY_VAR = %s\n", value);
    else
        printf("Environment variable not found\n");

    return 0;
}