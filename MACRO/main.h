/*
* This is header file for main.c
* Conditional Macro is defined here
* Author   : MUTHUGANESH S
* Date     : 08/01/2026 
* Filename : main.h
*/

// STAGE Macro is defined as 1
#define STAGE 1

/* 
* STAGE is 1 it gives AREA of square 
* STAGE is 2 it gives AREA of circle
*/

#if STAGE == 1
    //Area of the square
    #define AREA(SquareSide) (SquareSide * SquareSide)

#elif STAGE == 2
    //Area of the circle
    #define AREA(CircleRadius) (3.14 * CircleRadius * CircleRadius)

#endif
void DisplayArea(void); //function prototype declaration
