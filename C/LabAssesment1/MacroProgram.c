/*
* Program to demonstrate the Indicator using Macros
* Author   : MUTHUGANESH S
* Date     : 15/01/2026 
* Filename : MacroProgram.c
* retval   : void
*/

//header file
#include <stdio.h>

//macro
#define READBIT(VAR,POS) ((VAR >> POS) & 1)
#define SETBIT(VAR,POS) (VAR |= (1 << POS))
#define CLEARBIT(VAR,POS) (VAR &= ~(1 << POS))
#define ON 1
#define OFF 0
int main(){
    unsigned char Input;
    printf("Enter an integer (0-255): ");
    scanf("%hhu", &Input);

    //Read Switches
    unsigned char IgnitionSwitch=READBIT(Input,0);
    unsigned char RightIndicatorSwitch=READBIT(Input,1);
    unsigned char LeftIndicatorSwitch=READBIT(Input,2);

    CLEARBIT(Input,5);//Right Indicator Status 
    CLEARBIT(Input,6);//Ignition Status
    CLEARBIT(Input,7);//Left Indicator Status

    if(IgnitionSwitch==ON){
        SETBIT(Input,6); //Ignition ON

        if(RightIndicatorSwitch==ON && LeftIndicatorSwitch==OFF){
            SETBIT(Input,5); //Right Indicator ON
            SETBIT(Input,7); //Left Indicator ON
        }
        else if(RightIndicatorSwitch==ON){
            SETBIT(Input,5); //Left Indicator ON
        }
        else if(LeftIndicatorSwitch==ON){
            SETBIT(Input,7); //Right Indicator ON
        }
    }

    if(READBIT(Input,6)==ON){
        printf("Ignition Status: ON\n");
    }
    else{
        printf("Ignition Status: OFF\n");
    }

    if(READBIT(Input,5)==ON && READBIT(Input,7)==ON){
        printf("Parking On\n");
    }
    else if(READBIT(Input,5)==ON){
        printf("Right Indicator ON\n");
    }
    else if(READBIT(Input,7)==ON){
        printf("Left Indicator ON\n");
    }
    else{
        printf("Indicators OFF\n");
    }

    printf("Output Status (in decimal): %d\n", Input);
    return 0;

}