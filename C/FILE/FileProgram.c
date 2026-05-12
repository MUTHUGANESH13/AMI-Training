/*
*  Program read and wirte files
*  Author   : MUTHUGANESH S
*  Date     : 20/01/2026
*  Filename : FileProgram.c
*  retval   : void
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *SourcePointer,*DestinationPointer;
    char ch;
    SourcePointer = fopen("File1.txt", "r");
    DestinationPointer = fopen("File2.txt", "w");

    if(DestinationPointer == NULL)
    {
        printf("File not created\n");
        exit(1);
    }

    if (SourcePointer == NULL)
    {
        printf("File not found\n");
        exit(1);
    }

    while ((ch = fgetc(SourcePointer)) != EOF){
        fputc(ch, DestinationPointer);
    }
    printf("File copied successfully\n");
    fclose(DestinationPointer);
    fclose(SourcePointer);
    return 0;

}