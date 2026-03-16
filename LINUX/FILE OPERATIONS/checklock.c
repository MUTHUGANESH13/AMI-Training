/*
Program to check if a file is locked
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : checklock.c
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

    fd = open("lockfile.txt", O_RDWR | O_CREAT, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if(fcntl(fd, F_GETLK, &lock) == -1)
    {
        perror("fcntl");
        close(fd);
        exit(1);
    }

    if(lock.l_type == F_UNLCK)
    {
        printf("No locks currently prevent this lock request.\n");
    }
    else
    {
        printf("Lock detected:\n");
        printf("Process ID holding lock: %d\n", lock.l_pid);

        if(lock.l_type == F_RDLCK)
            printf("Lock type: READ LOCK\n");
        else if(lock.l_type == F_WRLCK)
            printf("Lock type: WRITE LOCK\n");

        printf("Start offset: %ld\n", lock.l_start);
        printf("Length: %ld\n", lock.l_len);
    }

    close(fd);
    return 0;
}