/*
*  Program to demonstrate vector
*  Author  : MUTHUGANESH S
*  Date    : 21/1/2026
*  Filename: Vector.cpp
*  retval  : void
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    // Declaring a vector of integers
    vector<int> V1;
    int Choice;

    cout<<"1.Sort\n2.Add Element\n3.Erase Element\n4.Display\n5.Exit\n\nEnter your Choice:";
    cin>>Choice;

    while(Choice!=5){

        // sort using STL sort function
        if(Choice==1)
            sort(V1.begin(),V1.end());

        //Adding element to the vector
        else if(Choice==2){
            int Value;
            cout<<"Enter the Element:";
            cin>>Value;
            V1.push_back(Value);
        }

        //Erasing element from the vector
        else if(Choice==3){
            int Value;
            cout<<"Enter the value:";
            cin>>Value;
            int index=-1;
            for(int i=0;i<V1.size();i++){
                if(V1[i]==Value){
                    index=i;
                    break;
                }
            }
            if(index != -1) {
                V1.erase(V1.begin()+index);
            }
            else{
                cout<<"Element not found\n";
            }
        }
        else if(Choice==4){
            for(int i=0;i<V1.size();i++)
                cout<<V1[i]<<" ";
            cout<<endl;
        }
        else
            break;

        cout<<"1.Sort\n2.Add Element\n3.Erase Element\n4.Display\n5.Exit\n\nEnter your Choice:";
        cin>>Choice;

        }

    return 0;
}