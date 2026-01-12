/*
* Program to demonstrate a macro,global variable and extern
* Author   : MUTHUGANESH S
* Date     : 08/01/2026
* Filename : main.c
* retval   : void
*/

//standard input output header file inclusion
#include <stdio.h>

//header file inclusion
#include "main.h"

//global variable declaration using conditionl macro
#if STAGE == 1
    extern float SquareSide; //global variable for square side

#elif STAGE == 2
    extern float CircleRadius; //global variable for circle radius

#endif
void DisplayArea(void); //function prototype declaration

//main function
int main() {
    DisplayArea(); //function call to display area
    return 0;
}