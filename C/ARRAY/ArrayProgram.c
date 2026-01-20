/*
*  Program to demonstrate Array operations
*  Author   : MUTHUGANESH S
*  Date     : 12/01/2026
*  Filename : ArrayProgram.c
*  retval   : void
*/

//header file   
#include <stdio.h>
#define SIZE 10

//function declaration
int EvenCount(int Array[]);
void AscendingSort(int Array[]);
void DescendingSort(int Array[]);
void RemoveDuplicates(int Array[], int *NewSize);

//main function
int main(){
    int Array[SIZE];

    //Get input from user
    printf("Enter %d integers:\n", SIZE);
    for(int i=0;i<SIZE;i++){
        scanf("%d", &Array[i]);
    }
    //Count even numbers in the array
    int EvenNumbers = EvenCount(Array);
    printf("\nNumber of even numbers in the array: %d\n", EvenNumbers);

    //Sort the array in ascending order
    AscendingSort(Array);
    printf("\nArray in ascending order: ");
    for(int i=0;i<SIZE;i++){
        printf("%d ", Array[i]);
    }
    printf("\n");

    //Sort the array in descending order
    DescendingSort(Array);
    printf("\nArray in descending order: ");
    for(int i=0;i<SIZE;i++){
        printf("%d ", Array[i]);
    }
    printf("\n");

    //Remove duplicates from the array
    int NewSize = SIZE;

    //Function call to remove duplicates
    RemoveDuplicates(Array, &NewSize);
    printf("\nArray after removing duplicates: ");

    //Display the new array
    for(int i=0;i<NewSize;i++){
        printf("%d ", Array[i]);
    }
    printf("\n");

    return 0;
}

//Function to count even numbers in the array
int EvenCount(int Array[]){
    int Count=0;

    for(int i=0;i<SIZE;i++){
        if(Array[i]%2==0){
            Count++;
        }
    }
    return Count;
}

//Function to sort the array in ascending order
void AscendingSort(int Array[]){
    int SwapVariable;

    for(int i=0;i<SIZE-1;i++){
        for(int j=i+1;j<SIZE;j++){
            if(Array[i]>Array[j]){

                //Swap the elements
                SwapVariable = Array[i];
                Array[i] = Array[j];
                Array[j] = SwapVariable;
            }
        }
    }
}

//Function to sort the array in descending order
void DescendingSort(int Array[]){
    int SwapVariable;

    for(int i=0;i<SIZE-1;i++){
        for(int j=i+1;j<SIZE;j++){
            if(Array[i]<Array[j]){

                //Swap the elements
                SwapVariable = Array[i];
                Array[i] = Array[j];
                Array[j] = SwapVariable;
            }
        }
    }
}

//remove the duplicate elements from the array
void RemoveDuplicates(int Array[], int *NewSize){
    //Create a new array to store unique elements
    int NewArray[SIZE];
    int Index = 0;

    //Check for duplicates and store unique elements
    for(int i=0;i<SIZE;i++){

        int IsDuplicate = 0; //Flag to check for duplicates

        for(int j=0;j<Index;j++){
            if(Array[i] == NewArray[j]){
                IsDuplicate = 1;
                break;
            }
        }
        if(!IsDuplicate){
            NewArray[Index++] = Array[i];
        }
    }

    //Copy unique elements back to original array
    for(int i=0;i<Index;i++){
        Array[i] = NewArray[i];
    }

    //Update the new size of the array
    *NewSize = Index;
}