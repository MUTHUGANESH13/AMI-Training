/*
*  Program to create a Class and show the use of types of Constructor in C++
*  Author  : MUTHUGANESH S
*  Date    : 21/1/2026
*  Filename: CarModel.cpp
*  retval  : void
*/

#include <iostream>
using namespace std;

class Car{
    string Model;
    string Brand;
    int MakeYear;
    int Price;
    public:
        // Default Constructor

        Car(){
            cout << "\nDefault Constructor called" << endl;
            Model = "Unknown";
            Brand = "Unknown";
            MakeYear = 0;
            Price = 0;
        }
        // Parameterized Constructor
        Car(string Model, string Brand, int MakeYear, int Price){
            cout << "\nParameterized Constructor called for Model: " << Model << endl;
            this->Model = Model;
            this->Brand = Brand;
            this->MakeYear = MakeYear;
            this->Price = Price;
        }

        //copy Constructor
        Car(const Car &c){
            cout << "\nCopy Constructor called for Model: " << c.Model << endl;
            Model = c.Model;
            Brand = c.Brand;
            MakeYear = c.MakeYear;
            Price = c.Price;
        }

        //destructor
        ~Car(){
            cout<<"\nDestructor called for Model: " << Model << endl;
        }
        void Display(){
            cout << "\nModel : " << Model << endl;
            cout << "Brand : " << Brand << endl;
            cout << "MakeYear : " << MakeYear << endl;
            cout << "Price : " << Price << endl;
        }
};

// Main function
int main(){

    //local scope to demonstrate Default Constructor
    {
        // Creating object using Default Constructor
        Car Car1;
        Car1.Display();
    }

    // Creating object using Parameterized Constructor
    Car Car2("Model S", "Tesla", 2020, 79999);
    Car2.Display();

    // Creating object using Copy Constructor
    Car Car3 = Car2;
    Car3.Display();

    return 0;
}