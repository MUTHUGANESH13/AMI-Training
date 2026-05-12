/*
Program to copy using System calls
Author   : MUTHUGANESH S
Date     : 02/02/2026
Filename : Copy.c
*/

//Header files
#include <fcntl.h>
#include <unistd.h>

int main(){

char buf[1024];

int src=open("a.txt",O_RDONLY);
int dest=open("b.txt",O_CREAT|O_WRONLY,0644);

int n;

while((n=read(src,buf,sizeof(buf)))>0)
write(dest,buf,n);

close(src);
close(dest);
}