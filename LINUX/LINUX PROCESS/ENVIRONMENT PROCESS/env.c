/*
Program to print environment variables
Author   : MUTHUGANESH S
Date     : 07/02/2026
Filename : env.c
*/

#include <stdio.h>

// Global variable that holds the environment variables
extern char **environ;

int main()
{
    char **env = environ;

    while(*env != NULL)
    {
        printf("%s\n", *env);
        env++;
    }

    return 0;
}