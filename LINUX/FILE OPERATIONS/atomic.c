/*
Program to implement atomic write
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : atomic.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("atomic.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid_t pid = fork();

    for(int i = 0; i < 10; i++)
    {
        char buffer[50];

        if(pid == 0)
        {
            sprintf(buffer, "Child process writing %d\n", i);
        }
        else
        {
            sprintf(buffer, "Parent process writing %d\n", i);
        }

        write(fd, buffer, strlen(buffer));

        sleep(1);
    }

    close(fd);
    return 0;
}