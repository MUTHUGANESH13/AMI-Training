/*
* Simple Program to Demonstrate Decision Making
* Author   : MUTHUGANESH S
* Date     : 09/01/2026
* Filename : DecisionMakingProgram.c
* retval   : void
*/

//header file
#include <stdio.h>

//Macros for Grade Limits
#define GRAGE_A 90
#define GRAGE_B 80  
#define GRAGE_C 70
#define GRAGE_D 60  
#define GRAGE_E 40
#define NUMSUBJECTS 5

int main(){

    int SubjectMark[NUMSUBJECTS];
    int TotalMark=0;
    float AverageMark;

    //Get marks for 5 subjects from user
    for(int i=0;i<NUMSUBJECTS;i++){
        printf("Enter mark for Subject %d: ", i+1);
        scanf("%d", &SubjectMark[i]);
        TotalMark += SubjectMark[i];
    }

    //Calculate average mark
    AverageMark = (float)TotalMark / NUMSUBJECTS;

    //Determine grade based on average mark
    if (AverageMark >= GRAGE_A) {
        printf("\nGrade A");
    } 
    else if (AverageMark >= GRAGE_B) {
        printf("\nGrade B");
    } 
    else if (AverageMark >= GRAGE_C) {
        printf("\nGrade C");
    } 
    else if (AverageMark >= GRAGE_D) {
        printf("\nGrade D");
    } 
    else if(AverageMark >= GRAGE_E) {
        printf("\nGrade E");
    }
    else {
        printf("\nGrade F");
    }
    return 0;
}