/*
Program to create a file and redirect the standard output to the file
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : red.c
*/

//Header files  
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;

    //Creating a file
    fd = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

    //Checking if the file is created
    if(fd < 0)
    {
        perror("open failed");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);

    printf("This line goes to the file\n");
    printf("Standard output redirected\n");

    close(fd);

    return 0;
}