/*
*  Program to demonstrate virtual functions in C++
*  Author  : MUTHUGANESH S
*  Date    : 28/1/2026
*  Filename: VirtualFunction.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

class Employee{
protected:
    string Name;
    int EmployeeID;
public:
    Employee(int id, string name) : EmployeeID(id), Name(name) {}

    // Virtual function to display employee details
    virtual void display(){
        cout << "Employee Details" << endl;
        cout << "Name: " << Name << ", Employee ID: " << EmployeeID << endl;
    }
};

class Salaried: public Employee{
    int WorkingDays;
    int DailyWage;
public:
    Salaried(int id, string n, int days, float salary)
        : Employee(id, n) {
        WorkingDays = days;
        DailyWage = salary;
    }

    // Overriding display function
    void display() {
        float totalSalary = WorkingDays * DailyWage;
        cout << "Employee Type: Salaried Employee" << endl;
        cout << "Employee ID: " << EmployeeID << endl;
        cout << "Name: " << Name << endl;
        cout << "Working Days: " << WorkingDays << endl;
        cout << "Total Salary: " << totalSalary << endl<<endl;
    }
};

class ContractLabour: public Employee{
    int DailyWage;
    int DaysWorked;
public:
    ContractLabour(int id, string n, int days, float wages)
        : Employee(id, n) {
        DaysWorked = days;
        DailyWage = wages;
    }

    // Overriding display function
    void display() {
        float totalWages = DaysWorked * DailyWage;
        cout << "Employee Type: Contract Labour" << endl;
        cout << "Employee ID: " << EmployeeID << endl;
        cout << "Name: " << Name << endl;
        cout << "Days Worked: " << DaysWorked << endl;
        cout << "Total Wages: " << totalWages << endl<<endl;
    }
};

int main() {
    Employee* emp1 = new Salaried(101, "Alice", 22, 1500);
    Employee* emp2 = new ContractLabour(102, "Bob", 20, 800);

    cout << "Using base class pointer to derived class objects:" << endl;

    // Calling display function using base class pointer

    emp1->display(); // Will call Salaried's display function

    emp2->display(); // Will call ContractLabour's display function

    return 0;
}