/*
Program to demonstrate the pre emption of threads
Author   : MUTHUGANESH S
Date     : 07/02/2026
Filename : pre.c
*/

#include <stdio.h>
#include <pthread.h>

int counter = 0;

//Function to increment the counter
void *increment(void *arg)
{
    for(int i = 0; i < 1000000; i++)
    {
        counter++;
    }
    return NULL;
}

int main()
{
    //Declare two threads
    pthread_t t1, t2;

    //Create two threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, increment, NULL);

    //Join the threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Counter Value: %d\n", counter);

    return 0;
}