/*
Program to create a file and duplicate the file descriptor
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : dup.c
*/

//header files
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd, fd_dup;

    //Creating a file
    fd = open("dup_example.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);

    if(fd < 0)
    {
        perror("open failed");
        return 1;
    }

    //Duplicating the file
    fd_dup = dup(fd);

    printf("Original FD : %d\n", fd);
    printf("Duplicated FD : %d\n", fd_dup);

    write(fd, "Hello ", 6);
    write(fd_dup, "World\n", 6);

    close(fd);
    close(fd_dup);

    return 0;
}