/*
*  Program to demonstrate Bitwise operations
*  Author   : MUTHUGANESH S
*  Date     : 09/01/2026
*  Filename : BitwiseProgram.c  
*  retval   : void
*/

//header file 
#include <stdio.h>

//macro definitions for bitwise operations
#define POS 4
#define ONE 1

//macro to read bit at POS
#define READBIT(VAR,BIT)    ((VAR >> BIT) & ONE)

//macro to set bit at POS
#define SETBIT(VAR,BIT)     (VAR |= (ONE << BIT))
int main(){
    int InputValue, OutputValue=0;
    printf("Enter an integer InputValue: ");
    scanf("%d", &InputValue);//Get input from user

    //Left shift the bits of InputValue by POS and store in OutputValue
    for(int i=0;i<POS;i++){

        if(READBIT(InputValue,i)==ONE){

            SETBIT(OutputValue,i+POS);

        }
    }

    //Display the output value
    printf("The OutputValue: %d", OutputValue);
    return 0;
}