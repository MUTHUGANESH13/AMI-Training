/*
Porgram to prevent file locking
Author   : MUTHUGANESH S
Date     : 05/02/2026
Filename : race.c
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

//Functions to lock and unlock the file
void lock_file(int fd)
{
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLKW, &lock);
}

//Functions to lock and unlock the file
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
    char buffer[50];

    fd = open("race.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid = fork();

    for(int i = 0; i < 5; i++)
    {
        lock_file(fd);

        if(pid == 0)
            sprintf(buffer, "Child process writing %d\n", i);
        else
            sprintf(buffer, "Parent process writing %d\n", i);

        write(fd, buffer, strlen(buffer));

        unlock_file(fd);

        usleep(100000);
    }

    close(fd);
    return 0;
}