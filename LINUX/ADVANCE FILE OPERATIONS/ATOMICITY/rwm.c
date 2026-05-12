/*
Program to read write modify  in atomic mode
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : rwm.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

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
    int fd;
    int value;
    pid_t pid;

    fd = open("counter.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid = fork();

    for(int i = 0; i < 5; i++)
    {
        lock_file(fd);

        lseek(fd, 0, SEEK_SET);
        read(fd, &value, sizeof(int));

        value++;

        lseek(fd, 0, SEEK_SET);
        write(fd, &value, sizeof(int));

        printf("Process %d updated counter to %d\n", getpid(), value);

        unlock_file(fd);

        sleep(1);
    }

    close(fd);
    return 0;
}