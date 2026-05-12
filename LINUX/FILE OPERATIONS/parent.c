/*
Program to implement parent child synchronization
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : parent.c
*/

//Header files
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

    printf("Process %d waiting for lock...\n", getpid());

    fcntl(fd, F_SETLKW, &lock);

    printf("Process %d acquired lock\n", getpid());
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
    int fd;
    pid_t pid;

    fd = open("sync.txt", O_RDWR | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid = fork();

    lock_file(fd);

    if(pid == 0)
    {
        write(fd, "Child writing to file\n", 22);
        sleep(3);
    }
    else
    {
        write(fd, "Parent writing to file\n", 23);
        sleep(3);
    }

    unlock_file(fd);

    printf("Process %d released lock\n", getpid());

    close(fd);

    return 0;
}