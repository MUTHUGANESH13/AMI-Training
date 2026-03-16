/*
Program to implement deadlock
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : deadlock.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

void lock_region(int fd, int start)
{
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = start;
    lock.l_len = 10;

    printf("Process %d trying to lock region starting at %d\n", getpid(), start);

    if(fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        exit(1);
    }

    printf("Process %d locked region %d\n", getpid(), start);
}

//Function to unlock a region
void unlock_region(int fd, int start)
{
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = start;
    lock.l_len = 10;

    fcntl(fd, F_SETLK, &lock);
}

//Main function
int main()
{
    int fd;
    pid_t pid;

    fd = open("deadlock.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid = fork();

    if(pid == 0)
    {
        lock_region(fd, 0);
        sleep(2);

        lock_region(fd, 20);

        unlock_region(fd, 20);
        unlock_region(fd, 0);
    }
    else
    {
        lock_region(fd, 20);
        sleep(2);

        lock_region(fd, 0);

        unlock_region(fd, 0);
        unlock_region(fd, 20);
    }

    close(fd);
    return 0;
}