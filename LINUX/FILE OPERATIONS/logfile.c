/*
Program to append log entries to a file
Author   : MUTHUGANESH S
Date     : 03/02/2026
Filename : logfile.c
*/

//Header files
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Function declaration
void lock_file(int fd)
{
    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLKW, &lock);
}

//Function declaration
void unlock_file(int fd)
{
    struct flock lock;

    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    fcntl(fd, F_SETLK, &lock);
}

//Main function
int main()
{
    int fd;
    pid_t pid;
    char buffer[200];
    time_t now;

    fd = open("logfile.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    pid = fork();

    for(int i = 0; i < 5; i++)
    {
        lock_file(fd);

        now = time(NULL);

        if(pid == 0)
            sprintf(buffer, "Child PID %d: log entry at %ld\n", getpid(), now);
        else
            sprintf(buffer, "Parent PID %d: log entry at %ld\n", getpid(), now);

        write(fd, buffer, strlen(buffer));

        unlock_file(fd);

        sleep(1);
    }

    close(fd);

    return 0;
}