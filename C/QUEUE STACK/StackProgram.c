/*
*  Program to implement a stack using linked list
*  Author: MUTHUGANESH S
*  Date  : 20/1/2026
*  File  : StackProgram.c
*  retval: void
*/

// Include necessary headers
#include <stdio.h>
#include <stdlib.h>

// Define boolean values and stack size
#define TRUE 1
#define FALSE 0
#define STACK_SIZE 3

// Define the Node structure
typedef struct Node {
    int Data;
    struct Node* Next;
} Node;

// Define the Stack structure
typedef struct Stack {
    Node* HeadNode;
    int Size;
} Stack;

// Function to create a new node
Node* CreateNode(int Data){

    Node* NewNode = (Node*)malloc(sizeof(Node));

    if(NewNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }

    NewNode->Data = Data;
    NewNode->Next = NULL;
    return NewNode;
}

// Function to push an element onto the stack
void Push(Stack* MyStack, int Data){

    Node* NewNode = CreateNode(Data);

    if(NewNode == NULL){
        printf("Stack Overflow\n");
        return;
    }

    if(MyStack->Size == STACK_SIZE){
        printf("Stack Overflow\n");
        free(NewNode);
        return;
    }
    
    MyStack->Size++;
    NewNode->Next = MyStack->HeadNode;
    MyStack->HeadNode = NewNode;
    printf("Pushed element: %d\n", Data);
}

// Function to pop an element from the stack
void Pop(Stack* MyStack){

    if(MyStack->HeadNode == NULL){
        printf("Stack Underflow\n");
        return;
    }

    Node* TempNode = MyStack->HeadNode;
    MyStack->HeadNode = MyStack->HeadNode->Next;
    MyStack->Size--;

    printf("Popped element: %d\n", TempNode->Data);

    free(TempNode);
}

// Function to check if the stack is empty
int IsEmpty(Stack* MyStack){
    return MyStack->HeadNode == NULL;
}

// Function to check if the stack is full
int IsFull(Stack* MyStack){
    return MyStack->Size == STACK_SIZE;
}

int main(void){
    Stack MyStack;
    MyStack.HeadNode = NULL;
    MyStack.Size = 0;

    int Value,Data;

    printf("Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. check Empty\n");
    printf("4. check Full\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &Value);

    while(Value != 5){
        switch (Value)
    {
    case 1:
        printf("Enter data to push: ");
        scanf("%d", &Data);
        Push(&MyStack, Data);
        break;
    
    case 2:
        Pop(&MyStack);
        break;

    case 3:
        if(IsEmpty(&MyStack)==TRUE){
            printf("Stack is empty\n");
        } else {
            printf("Stack is not empty\n");
        }
        break;  

    case 4:
        if(IsFull(&MyStack)==TRUE){
            printf("Stack is full\n");
        } else {
            printf("Stack is not full\n");
        }
        break;

    case 5:
        exit(0);

    default:
        break;
    }
        printf("\nEnter your choice: ");
        scanf("%d", &Value);
    }

    return 0;
}