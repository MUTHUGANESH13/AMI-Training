/*
Program to demonstrate race condition
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : race.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int fd = open("shared.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid_t pid = fork();

    for(int i = 0; i < 10; i++)
    {
        if(pid == 0)
        {
            write(fd, "Child writing\n", 14);
        }
        else
        {
            write(fd, "Parent writing\n", 15);
        }

        usleep(100000);
    }

    close(fd);
}