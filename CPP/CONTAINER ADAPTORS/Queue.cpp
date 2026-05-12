/*
*  Program to demonstarte queue
*  Author  : MUTHUGANESH S
*  Date    : 05/2/2026
*  Filename: Queue.cpp
*  retval  : void
*/

#include <iostream>
#include <queue>
using namespace std;

// Function to display elements of the queue
void Display(queue <int> q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(void){

    queue <int> q;
    cout<<"1.Add Elements\n2.Check Status\n3.Access next Element\n";
    cout<<"4.Access Last Element\n5.Remove Element\n6.Swap\n7.Display\n8.Exit\n";
    int choice, value;
    queue <int> q2;
    while(choice!=8){
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch(choice){
            // Adding elements to the queue
            case 1:
                cout<<"Enter the value: ";
                cin>>value;
                q.push(value);
                break;

            // Checking status
            case 2:
                if(q.empty())
                    cout<<"Queue is empty"<<endl;
                else
                    cout<<"Size of Queue: "<<q.size()<<endl;
                break;

            // Accessing next elements
            case 3:
                cout<<"Next Element: "<<q.front()<<endl;
                break;

            // Accessing last elements
            case 4:
                cout<<"Last Element: "<<q.back()<<endl;
                break;

            // Removing elements
            case 5:
                q.pop();
                break;

            // Swapping queues
            case 6:
                cout<<"Enter the second queue of "<<q.size()<<" elements: "<<endl;
                for(int i=0;i<q.size();i++){
                    cin>>value;
                    q2.push(value);
                }
                q.swap(q2);
                cout<<"Queues Swapped"<<endl;
                cout<<"Elements in the queue1: "<<endl;
                Display(q);
                cout<<"Elements in the queue2: "<<endl;
                Display(q2);
                break;

            // Displaying elements
            case 7:
                cout<<"Elements in the queue: "<<endl;
                Display(q);
                break;

            // Exiting
            case 8:
                cout<<"Exiting..."<<endl;
                break;
        } 
    }
    return 0;
}