/*
Program to implement atomic log file
Author   : MUTHUGANESH S
Date     : 05/02/2026
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
    int fd;
    pid_t pid;
    char buffer[100];

    fd = open("atomic_log.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid = fork();

    for(int i = 0; i < 5; i++)
    {
        if(pid == 0)
            sprintf(buffer, "Child process %d writing line %d\n", getpid(), i);
        else
            sprintf(buffer, "Parent process %d writing line %d\n", getpid(), i);

        write(fd, buffer, strlen(buffer));

        sleep(1);
    }

    close(fd);
    return 0;
}