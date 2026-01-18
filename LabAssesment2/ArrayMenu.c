/*
*  Program to Create Menu that will have differnet functionaities of Arrays
*  Author   : MUTHUGANESH S
*  Date     : 16/01/2026
*  Filename : ArrayMenu.c
*  retval   : void
*/

#include <stdio.h>
#define SIZE 10

// Function Prototypes
void GetArray(int Array[],int Size);
void DisplayArray(int Array[],int Size,int Choice);
void ReverseArray(int Array[],int Size);
void SortArray(int Array[],int Size,int Choice);

int main(void){

    int Array[SIZE];

    printf("Menu for Array Operations:\n");
    printf("1.Get Array\n");
    printf("2.Display Array\n");
    printf("3.Reverse Array\n");
    printf("4.Sort Array\n");
    printf("5.Exit\n");

    int Choice=0,SubChoice;
    while(Choice != 5){
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &Choice);

        switch(Choice){
            case 1:

                GetArray(Array, SIZE);
                break;

            case 2:

                printf("1. Displaying the array elements:\n2.Odd Elements\n3.Even Elements\n");
                printf("Enter your choice (1-3): ");
                scanf("%d", &SubChoice);

                DisplayArray(Array, SIZE, SubChoice);

                break;

            case 3:

                ReverseArray(Array, SIZE);
                break;

            case 4:

                printf("1.Ascending\n2.Descending\n");
                printf("Enter your choice (1-2): ");
                scanf("%d", &SubChoice);

                SortArray(Array, SIZE, SubChoice);

                break;

            case 5:

                printf("Exiting the program.\n");
                break;

            default:

                printf("Invalid choice. Please try again.\n");
                break;

        }
    }
}

//Function to get array elements from user
void GetArray(int Array[],int Size){

    printf("Enter %d integers to initialize the array:\n", Size);

    for(int i = 0; i < Size; i++){
        scanf("%d", &Array[i]);
    }
}

//Function to display array elements based on choice
void DisplayArray(int Array[],int Size,int Choice){

    if(Choice==1){
        printf("Array elements:\n");
    }
    else if(Choice==2){
        printf("Odd elements:\n");
    }
    else if(Choice==3){
        printf("Even elements:\n");
    }

    for(int i=0;i<Size;i++){
        if(Choice == 1){
            printf("%d ",Array[i]);
        }
        else if(Choice == 2 && Array[i] % 2 != 0){
            printf("%d ",Array[i]);
        }
        else if(Choice == 3 && Array[i] % 2 == 0){
            printf("%d ",Array[i]);
        }
    }
    printf("\n");

}

//Function to reverse the array
void ReverseArray(int Array[],int Size){

    for(int i=0;i<Size/2;i++){
        int temp = Array[i];
        Array[i] = Array[Size - i - 1];
        Array[Size - i - 1] = temp;
    }

    DisplayArray(Array,Size,1);
    printf("\n");
}

//Function to sort the array based on choice
void SortArray(int Array[],int Size,int Choice){

    if(Choice == 1){
        printf("Ascending order:\n");
        // Ascending order
        for(int i=0;i<Size-1;i++){
            for(int j=0;j<Size-i-1;j++){
                if(Array[j] > Array[j+1]){
                    int temp = Array[j];
                    Array[j] = Array[j+1];
                    Array[j+1] = temp;
                }
            }
        }
    }
    else if(Choice == 2){
        printf("Descending order:\n");
        // Descending order
        for(int i=0;i<Size-1;i++){
            for(int j=0;j<Size-i-1;j++){
                if(Array[j] < Array[j+1]){
                    int temp = Array[j];
                    Array[j] = Array[j+1];
                    Array[j+1] = temp;
                }
            }
        }
    }

    DisplayArray(Array,Size,1);
    printf("\n");
}