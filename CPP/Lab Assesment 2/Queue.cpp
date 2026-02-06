/*
*  Program to demostrate queue using the list
*  Author  : MUTHUGANESH S
*  Date    : 06/2/2026
*  Filename: Queue.cpp
*  retval  : void
*/

#include <iostream>
#include <list>
using namespace std;

class Queue {
    list<int> q;

public:
    bool empty() {
        return q.empty();
    }   

    int size() {
        return q.size();
    }

    void swap(){
        q.swap(q);
    }

    int front() {
        if (!q.empty())
            return q.front();
    }

    int back() {
        if (!q.empty())
            return q.back();
    }

    void push(int value) {
        q.push_back(value);
    }

    void pop() {
        if (!q.empty())
            q.pop_front();
    }

    void display() {
        for (int value : q) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main(){
    Queue q;

    cout<<"1.check empty\n2.size\n3.front\n4.back\n5.push\n";
    cout<<"6.pop\n7.display\n8.exit\n";
    int choice, value;

    while(choice!=8){

        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice){

            // Check if queue is empty
            case 1:

                if(q.empty())
                    cout<<"Queue is empty"<<endl;
                else
                    cout<<"Queue is not empty"<<endl;
                break;

            // Size of the queue
            case 2:
                cout<<"Size of Queue: "<<q.size()<<endl;
                break;

            // Accessing next elements
            case 3:
                cout<<"Front Element: "<<q.front()<<endl;
                break;

            // Accessing last elements
            case 4:
                cout<<"Back Element: "<<q.back()<<endl;
                break;

            // Adding elements to the queue
            case 5:
                cout<<"Enter value to push: ";
                cin>>value;
                q.push(value);
                break;

            // Removing elements from the queue
            case 6:
                q.pop();
                break;

            // Displaying the queue
            case 7:
                q.display();
                break;

            // Exiting the program
            case 8:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}