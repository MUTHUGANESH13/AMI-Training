/*
*  Program to demonstrate basic inheritance in C++
*  Author  : MUTHUGANESH S
*  Date    : 24/1/2026
*  Filename: Employee.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

// Base class   
class Employee{

private:
    string Name;
    int Age;
    string Gender;

public:
    Employee(string Name, int Age, string Gender)
    {
        this->Name = Name;
        this->Age = Age;
        this->Gender = Gender;
    }

    void Display(){
        cout <<"Name:" << Name << endl;
        cout <<"Age:" << Age << endl;
        cout <<"Gender:" << Gender << endl;
    }

};

// Derived class 1
class EmployeeDetails : public Employee{

    string EmployeeDepartment;
    int EmployeeID;

public:
    EmployeeDetails(string Name, int Age, string Gender, 
    string EmployeeDepartment,int EmployeeID):Employee(Name, Age, Gender){
        this->EmployeeDepartment = EmployeeDepartment;
        this->EmployeeID = EmployeeID;
    }

    void Disp(){
        Display();
        cout <<"Employee Department:" << EmployeeDepartment << endl;
        cout <<"Employee ID:" << EmployeeID << endl;
    }

};

//Derived class 2
class EmployeeSalary : public EmployeeDetails{

    double Salary;
    int YearJoined;

public:
    EmployeeSalary(string Name, int Age, string Gender, 
    string EmployeeDepartment,int EmployeeID, double Salary, int YearJoined):
    EmployeeDetails(Name, Age, Gender, EmployeeDepartment, EmployeeID){
        this->Salary = Salary;
        this->YearJoined = YearJoined;
    }

    void DisplayInfo(){
        Disp();
        cout <<"Salary:" << Salary << endl;
        cout <<"Year Joined:" << YearJoined << endl;
    }

};

int main() {
    // Creating an object of the derived class
    EmployeeSalary emp("MUTHUGANESH S", 25, "Male", "IT", 101, 75000.50, 2020);

    // Accessing member functions of the derived class
    emp.DisplayInfo();
    
    return 0;
}
