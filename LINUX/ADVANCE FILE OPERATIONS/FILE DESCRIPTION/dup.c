/*
Program to create a file and duplicate the file descriptor
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : dup.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    //Declaring file descriptors
    int fd1, fd2;

    //Creating a file
    fd1 = open("test.txt", O_CREAT | O_RDWR, 0644);

    //Duplicating the file
    fd2 = dup(fd1);

    //Print the file descriptors
    printf("Original FD: %d\n", fd1);
    printf("Duplicate FD: %d\n", fd2);

    close(fd1);

    printf("Closed fd1\n");

    write(fd2, "Hello\n", 6);

    close(fd2);

    return 0;
}