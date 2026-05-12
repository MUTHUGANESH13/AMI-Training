/*
Program to display the size of files provided as command-line arguments
Author   : MUTHUGANESH S
Date     : 08/02/2026
Filename : filesize.c
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    long size;
    int i;

    if(argc < 2)
    {
        printf("Usage: %s filename1 filename2 ...\n", argv[0]);
        return 1;
    }

    for(i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            printf("Cannot open file %s\n", argv[i]);
            continue;
        }

        fseek(fp, 0, SEEK_END);
        size = ftell(fp);

        printf("File: %s Size: %ld bytes\n", argv[i], size);

        fclose(fp);
    }

    return 0;
}