/*
* Program to implement a Queue using linked list
* Author: MUTHUGANESH S
* Date  : 20/1/2026
* File  : QueueProgram.c
* retval: void
*/

// Include necessary headers
#include <stdio.h>
#include <stdlib.h>

// Define queue size
#define MAX_QUEUE_SIZE 4

// Define the Node structure
typedef struct Node {
    int Data;
    struct Node* Next;
} Node;

// Define the Queue structure
typedef struct Queue {
    Node* Front;
    Node* Rear;
    int Size;
} Queue;

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

// Function to enqueue an element into the queue
void Enqueue(Queue* MyQueue, int Data){
    if(MyQueue->Size == MAX_QUEUE_SIZE){
        printf("Queue Overflow\n");
        return;
    }

    Node* NewNode = CreateNode(Data);
    if(NewNode == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    if(MyQueue->Rear == NULL){
        MyQueue->Front = MyQueue->Rear = NewNode;
    } 
    else {
        MyQueue->Rear->Next = NewNode;
        MyQueue->Rear = NewNode;
    }

    MyQueue->Size++;
    printf("Enqueued element: %d\n", Data);
}

// Function to dequeue an element from the queue
void Dequeue(Queue* MyQueue){

    if(MyQueue->Size == 0){
        printf("Queue Underflow\n");
        return;
    }

    Node* TempNode = MyQueue->Front;
    MyQueue->Front = MyQueue->Front->Next;

    if(MyQueue->Front == NULL){
        MyQueue->Rear = NULL;
    }

    MyQueue->Size--;
    printf("Dequeued element: %d\n", TempNode->Data);
    free(TempNode);
}

int main(void){
    // Initialize the queue
    Queue MyQueue;
    MyQueue.Front = NULL;
    MyQueue.Rear = NULL;
    MyQueue.Size = 0;

    printf("Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");

    int Value, Data;
    printf("Enter your choice: ");
    scanf("%d", &Value);

    while(Value != 3){
        switch(Value){

            case 1:

                printf("Enter data to enqueue: ");
                scanf("%d", &Data);
                Enqueue(&MyQueue, Data);
                break;

            case 2:

                Dequeue(&MyQueue);
                break;

            default:

                printf("Invalid choice\n");
                break;

        }

        printf("\nEnter your choice: ");
        scanf("%d", &Value);
    }
    
    return 0;
}