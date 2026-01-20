/*
* Program to display the main function definition
* Author   : MUTHUGANESH S
* Date     : 08/01/2026
* Filename : display.c
* retval   : void
*/

//standard input output header file inclusion
#include <stdio.h>

//header file inclusion
#include "main.h"

//function definition to display area
void DisplayArea(void) {

    //conditional compilation based on STAGE macro
    #if STAGE == 1

        //extern declaration of side variable
        float SquareSide=5.0;

        //calculate area of square
        float SquareArea = AREA(SquareSide); 

        //display area of square
        printf("Area of Square with side %f is: %f\n", SquareSide, SquareArea);

    #elif STAGE == 2

        //extern declaration of radius variable
        float CircleRadius=7.0;

        //calculate area of circle
        float CircleArea = AREA(CircleRadius); 

        //display area of circle
        printf("Area of Circle with radius %f is: %f\n", CircleRadius, CircleArea);

    #endif
}