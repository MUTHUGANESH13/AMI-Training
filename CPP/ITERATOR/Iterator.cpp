/*
*  Program to demonstrate demostrate iterator in deque
*  Author  : MUTHUGANESH S
*  Date    : 05/2/2026
*  Filename: Iterator.cpp
*  retval  : void
*/

#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int>d;
    int Choice, value;

    cout<<"1. Insert at back\n2. Insert at front\n3.Delete from back\n";    
    cout<<"4.Delete from front\n5.Erase\n6.Display\n7.Exit\n";
    while(Choice!=7){

        cout<<"\nEnter your choice: ";
        cin>>Choice;

        switch(Choice){

            // Inserting elements at back
            case 1:
                cout<<"Enter value to insert at back: ";
                cin>>value;
                d.push_back(value);
                break;

            // Inserting elements at front
            case 2:
                cout<<"Enter value to insert at front: ";
                cin>>value;
                d.push_front(value);
                break;

            // Deleting elements from back
            case 3:
                if(!d.empty()){
                    d.pop_back();
                    cout<<"Deleted from back\n";
                } else {
                    cout<<"Deque is empty\n";
                }
                break;            

            // Deleting elements from front
            case 4:
                if(!d.empty()){
                    d.pop_front();
                    cout<<"Deleted from front\n";
                } else {
                    cout<<"Deque is empty\n";
                }
                break;

            // Erasing elements
            case 5:
                if(!d.empty()){
                    d.erase(d.begin());
                    cout<<"Erased first element\n";
                } else {
                    cout<<"Deque is empty\n";
                }
                break;

            // Displaying elements
            case 6:
                cout<<"Deque elements: ";
                for(auto it = d.begin(); it != d.end(); ++it){
                    cout<<*it<<" ";
                }
                cout<<endl;
                break;

            // Exiting
            case 7:
                cout<<"Exiting...\n";
                break;

            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    }

    return 0;
}