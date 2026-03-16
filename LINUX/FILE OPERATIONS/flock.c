/*
Program to implement file locking
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : flock.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int fd;
    struct flock lock;

    fd = open("data.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 50;
    lock.l_pid = getpid();

    printf("Process %d trying to acquire lock...\n", getpid());

    if(fcntl(fd, F_SETLKW, &lock) == -1)
    {
        perror("fcntl");
        exit(1);
    }

    printf("Lock acquired by process %d\n", getpid());
    printf("Writing to file...\n");

    write(fd, "Locked region write\n", 20);

    sleep(10);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    printf("Lock released by process %d\n", getpid());

    close(fd);

    return 0;
}