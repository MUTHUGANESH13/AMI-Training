/*
*  Program to demonstrate String operations without using string.h functions
*  Author   : MUTHUGANESH S
*  Date     : 14/01/2026
*  Filename : StringProgram.c
*  retval   : void
*/

//header file   
#include <stdio.h> 

//function declaration
void StringCopy(char Destination[], char Source[]);
int StringCompare(char String1[], char String2[]);
void StringReverse(char Source[], char Reversed[]);
void RemoveSpaces(char Source[], char Result[]);

int main(){

    char String1[100];
    char String2[100];
    char CopyString[100];
    char ReverseString[100];
    char NoSpaceString[100];

    printf("Enter the first string : ");
    gets(String1); //get the string from user
    printf("Enter the second string : ");
    gets(String2); //get the string from user

    //copy String1 to CopyString
    StringCopy(CopyString, String1);
    printf("\nCopied String : %s\n", CopyString);

     //compare String1 and String2
    int CompareValue;//use to store comparison result
    CompareValue = StringCompare(String1, String2);

    printf("\nComparison Result: ");
    if(CompareValue==0){
        printf("Strings are equal.\n");
    }
    else if(CompareValue<0){
        printf("String1 is less than String2.\n");
    }
    else{
        printf("String1 is greater than String2.\n");
    }

    //reverse String1
    StringReverse(String1, ReverseString);
    printf("\nReversed [%s] is %s\n", String1, ReverseString);

    //remove spaces from String1
    RemoveSpaces(String1, NoSpaceString);
    printf("\n%s after removing spaces : %s\n", String1, NoSpaceString);

    return 0;
}

//1.Function to copy one string to another
void StringCopy(char Destination[], char Source[]){
    int i = 0;

    //Copy each character from Source to Destination
    while(Source[i] != '\0'){
        Destination[i] = Source[i];
        i++;
    }
    Destination[i] = '\0'; //Null-terminate the destination string
}

//2.Function to compare two strings
int StringCompare(char String1[], char String2[]){
    int i = 0;

    //Compare each character of both strings
    while(String1[i] != '\0' && String2[i] != '\0'){
        if(String1[i] != String2[i]){

            //Return difference if characters are not equal
            return String1[i] - String2[i];
        }
        i++;
    }

    //If one string ends, check their lengths
    return String1[i] - String2[i];
}

//3.Function to reverse a string
void StringReverse(char Source[], char Reversed[]){
    int Length = 0;

    //Calculate the length of the source string
    while(Source[Length] != '\0'){
        Length++;
    }

    //Reverse the string
    for(int i = 0; i < Length; i++){
        Reversed[i] = Source[Length - i - 1];
    }

    //Null-terminate the reversed string
    Reversed[Length] = '\0';
}

//4.Function to remove spaces from a string
void RemoveSpaces(char Source[], char Result[]){
    int i = 0, j = 0;

    //Remove spaces from the source string
    while(Source[i] != '\0'){
        if(Source[i] != ' '){
            Result[j] = Source[i];
            j++;
        }
        i++;
    }

    //Null-terminate the result string
    Result[j] = '\0';
}