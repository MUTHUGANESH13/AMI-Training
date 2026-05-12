/*
* Program to demonstrate a function with parameters and return  value
* Author   : MUTHUGANESH S
* Date     : 16/01/2026
* Filename : FunctionProgram.c
* retval   : void
*/

#include <stdio.h>

//function declarations
unsigned char SetBit(unsigned char Num, int Pos);
unsigned char ResetBit(unsigned char Num, int Pos);
unsigned char ToggleBit(unsigned char Num, int Pos);
int ReadBit(unsigned char Num, int Pos);
void IntToString(int Num, char Result[]);
void Reverse(char Str[], char Reversed[]);

int main(void){
    int Position, Result;
    unsigned char Input;
    printf("Enter an integer: ");
    scanf("%hhu", &Input);
    printf("Enter the bit position to set (0-31): ");
    scanf("%d", &Position);

    // Function call to set the bit
    Result = SetBit(Input, Position);
    printf("Result after setting bit: %d\n", Result);
    
    // Function call to reset the bit
    Result=ResetBit(Input, Position);
    printf("Result after resetting bit: %d\n", Result);

    // Function call to toggle the bit
    Result=ToggleBit(Input, Position);
    printf("Result after toggling bit: %d\n", Result);

    // Function call to read the bit
    Result=ReadBit(Input, Position);
    printf("Value of the bit at position %d: %d\n", Position, Result);

    // Function call to convert integer to string
    char StringValue[100];
    IntToString(Input, StringValue);
    printf("String value of the integer: %s\n", StringValue);

    char ReversedString[100];
    Reverse(StringValue, ReversedString);
    printf("Reversed string value: %s\n", ReversedString);

    return 0;

}

unsigned char SetBit(unsigned char Num, int Pos){
    unsigned char Value;
    Value=Num | (1 << Pos);
    return Value;
}   

unsigned char ResetBit(unsigned char Num, int Pos){
    unsigned char Value;
    Value=Num & ~(1 << Pos);
    return Value;
}

unsigned char ToggleBit(unsigned char Num, int Pos){
    unsigned char Value;
    Value=Num ^ (1 << Pos);
    return Value;
}
int ReadBit(unsigned char Num, int Pos){
    int Value;
    Value=(Num >> Pos) & 1;
    return Value;
}

void IntToString(int Num, char Result[])
{
    int i = 0, j;
    char Temp[20];

    if (Num == 0)
    {
        Result[i++] = '0';
        Result[i] = '\0';
        return;
    }

    while (Num > 0)
    {
        Temp[i++] = (Num % 10) + '0';
        Num /= 10;
    }

    for (j = 0; j < i; j++)
        Result[j] = Temp[i - j - 1];

    Result[i] = '\0';
}

void Reverse(char Str[], char Reversed[])
{
    int len = 0, i;
    while (Str[len] != '\0')
        len++;

    for (i = 0; i < len; i++)
        Reversed[i] = Str[len - i - 1];

    Reversed[len] = '\0';
}