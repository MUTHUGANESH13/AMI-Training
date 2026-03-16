/*
Program to implement file locking    
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : lock.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

void lock_file(int fd)
{
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLKW, &lock);
}

void unlock_file(int fd)
{
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLK, &lock);
}

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
        lock_file(fd);

        if(pid == 0)
        {
            write(fd, "Child writing\n", 14);
        }
        else
        {
            write(fd, "Parent writing\n", 15);
        }

        unlock_file(fd);

        usleep(100000);
    }

    close(fd);
}