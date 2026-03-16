/*
Program to create 3 files
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : ThreeFiles.c
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    //Declaring file descriptors
    int fd1, fd2, fd3;

    //Creating 3 files
    fd1 = open("file1.txt", O_CREAT | O_RDWR, 0644);
    fd2 = open("file2.txt", O_CREAT | O_RDWR, 0644);
    fd3 = open("file3.txt", O_CREAT | O_RDWR, 0644);

    if(fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("File open error");
        return 1;
    }

    printf("File Descriptor for file1.txt : %d\n", fd1);
    printf("File Descriptor for file2.txt : %d\n", fd2);
    printf("File Descriptor for file3.txt : %d\n", fd3);

    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}