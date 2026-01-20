/*
* Program to demonstrate dynamic memory allocation
* Author: MUTHUGANESH S
* Date  : 16/01/2026
* Filename : DynamicMemory.c
* retval : void
*/

#include <stdio.h>
#include <stdlib.h>
int main(void){
    int *Array;
    int Size, i;

    printf("Enter the size of the array for malloc: ");
    scanf("%d", &Size);
    
    // malloc is used to allocate memory allocation
    Array = (int *)malloc(Size * sizeof(int));
    if (Array == NULL){
        printf("Memory allocation failed\n");
        return 0;
    }

    printf("\nBefore initialization of malloc:\n");
    for(int i=0;i<Size;i++){
        printf("%d ",Array[i]);
    }
    printf("\n\nEnter %d integers to initialize the array:\n", Size);
    // Initializing the allocated memory
    for(i = 0; i < Size; i++){
        scanf("%d", &Array[i]);
    }

    printf("\nAfter initialization of malloc:\n");
    for(int i=0;i<Size;i++){
        printf("%d ",Array[i]);
    }

    //realloc is used to reallocate memory
    int NewSize;
    printf("\n\nEnter the new size of the array: ");
    scanf("%d", &NewSize);
    Array = (int *)realloc(Array, NewSize * sizeof(int));
    if (Array == NULL){
        printf("Memory reallocation failed\n");
        return 0;
    }

    printf("\nAfter reallocation of realloc:\n");
    for(int i=0;i<NewSize;i++){
        printf("%d ",Array[i]);
    }

    // Freeing the allocated memory
    free(Array);

    //calloc is used to allocate memory and initialize to zero
    printf("\n\nEnter the size of the array for calloc: ");
    scanf("%d", &Size);
    Array = (int *)calloc(Size, sizeof(int));

    printf("\nBefore initialization of calloc:\n");
    for(int i=0;i<Size;i++){
        printf("%d ",Array[i]);
    }
    printf("\n\nEnter %d integers to initialize the array:\n", Size);
    // Initializing the allocated memory
    for(i = 0; i < Size; i++){
        scanf("%d", &Array[i]);
    }

    printf("\nAfter initialization of calloc:\n");
    for(int i=0;i<Size;i++){
        printf("%d ",Array[i]);
    }

    // Freeing the allocated memory
    free(Array);

    return 0;
}