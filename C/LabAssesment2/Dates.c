/*
* Program count number of days between two dates using structures
* Author   : MUTHUGANESH S
* Date     : 16/01/2026
* Filename : Dates.c
* retval   : void
*/

#include <stdio.h>
struct Date {
    int Day;
    int Month;
    int Year;
};
int IsLeapYear(int Year);
int DaysInMonth(int Month, int Year);
int DaysBetweenDates(struct Date Date1, struct Date Date2);

int main(void){
    struct Date Date1;
    struct Date Date2;

    printf("Enter first date (DD MM YYYY): ");
    scanf("%d %d %d", &Date1.Day, &Date1.Month, &Date1.Year);

    printf("Enter second date (DD MM YYYY): ");
    scanf("%d %d %d", &Date2.Day, &Date2.Month, &Date2.Year);

    int Days=DaysBetweenDates(Date1, Date2);
    printf("Number of days between the two dates: %d\n", Days);

    return 0;
}

int IsLeapYear(int Year) {
    
    if((Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0))
        return 1;
    else
        return 0;
}
int DaysInMonth(int Month, int Year) {
    if(Month == 2) {
        if(IsLeapYear(Year)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if(Month == 4 || Month == 6 || Month == 9 || Month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int DaysBetweenDates(struct Date Date1, struct Date Date2) {
    if (Date1.Year > Date2.Year || 
       (Date1.Year == Date2.Year && Date1.Month > Date2.Month) || 
       (Date1.Year == Date2.Year && Date1.Month == Date2.Month && Date1.Day > Date2.Day)) {
        struct Date Temp = Date1;
        Date1 = Date2;
        Date2 = Temp;
    }

    int Days = 0;

    while (Date1.Year < Date2.Year || Date1.Month < Date2.Month || Date1.Day < Date2.Day) {
        Days++;
        Date1.Day++;
        if (Date1.Day > DaysInMonth(Date1.Month, Date1.Year)) {
            Date1.Day = 1;
            Date1.Month++;
            if (Date1.Month > 12) {
                Date1.Month = 1;
                Date1.Year++;
            }
        }
    }

    return Days;
}