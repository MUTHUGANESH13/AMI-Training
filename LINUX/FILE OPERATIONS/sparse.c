/*
Program to create a sparse file
Author   : MUTHUGANESH S
Date     : 04/02/2026    
Filename : sparse.c
*/

//Header files
#include <fcntl.h>
#include <unistd.h>

int main(){

//Creating a sparse file
int fd=open("sparse.txt",O_CREAT|O_WRONLY,0644);

lseek(fd,10000,SEEK_SET);

write(fd,"A",1);

close(fd);
}