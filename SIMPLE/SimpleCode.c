//Documentation Section

/*
* Simple Code to Get INTEGER and FLOAT and Size of both
* Author   : MUTHUGANESH S
* Date     : 07/01/2026
* File name: SimpleCode.c
* retval   : void
*/

//Preprocessor Section
#include <stdio.h>

//Main Section
int main() {
    //variable declaration 
    int IntValue; 
    float FloatValue;

    printf("Enter an integer value: ");
    scanf("%d", &IntValue);
    printf("Enter a float value: ");
    scanf("%f", &FloatValue);

    printf("You entered integer: %d\n", IntValue);
    printf("You entered float: %f\n", FloatValue);

    printf("Size of integer: %zu bytes\n", sizeof(IntValue));
    printf("Size of float: %zu bytes\n", sizeof(FloatValue));

    return 0;
}