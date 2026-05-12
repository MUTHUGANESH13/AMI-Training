/*
Program to illustarte lseek()
Author   : MUTHUGANESH S
Date     : 01/02/2026
Filename : lseek.c
*/

//Header files
#include <fcntl.h>
#include <unistd.h>

int main(){

int fd=open("hello.txt",O_RDONLY);

lseek(fd,0,SEEK_SET);//start of file
lseek(fd,5,SEEK_SET);//5th byte
lseek(fd,0,SEEK_END);//end of file

close(fd);
}