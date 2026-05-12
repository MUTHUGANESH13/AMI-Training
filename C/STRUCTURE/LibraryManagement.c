/*
* Library Management System
* using functions and structures.
* Author   : MUTHUGANESH S
* Date     : 16/01/2026
* Filename : LibraryManagement.c
* retval   : void
*/

#include <stdio.h>
#define SIZE 5

// Structure Declaration
struct LibraryManagement
{
    int Price;
    int BookID;
    char BookName[20];
};

// Function Prototype
void UploadBook(struct  LibraryManagement Library[]);
void Details(struct  LibraryManagement Library[],int ID);

int main(void){
    struct LibraryManagement Library[SIZE];// Array of Structures

    // Function Call for Uploading Book Details
    UploadBook(Library);
    int ID;
    printf("\nEnter Book ID for Book Details: ");
    scanf("%d",&ID);

    // Function Call for Book Details by Book ID
    Details(Library,ID);

    return 0;
}

void UploadBook(struct LibraryManagement Library[]){
    printf("Enter 5 Books Details : \n");
    
    for(int i=0;i<SIZE;i++){

        printf("\nEnter %d.Book Name : ", i+1);
        scanf("%s",Library[i].BookName);

        printf("Enter Book ID : ");
        scanf("%d",&Library[i].BookID);

        printf("Enter Book Price : ");
        scanf("%d",&Library[i].Price);
    }
}

// Function Definition for Book Details by Book ID
void Details(struct  LibraryManagement Library[],int ID){
    
    for(int i=0;i<SIZE;i++){
        if(Library[i].BookID == ID){
            printf("Book Name : %s\n",Library[i].BookName);
            printf("Book ID   : %d\n",Library[i].BookID);
            printf("Book Price: %d\n",Library[i].Price);
        }
    }

}