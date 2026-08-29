/* This Program helps you understand Queue using Linked Lists. */


#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *next;
};

// Front and Rear pointers
struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (rear == NULL) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into queue\n", value);
}

// Dequeue operation
void dequeue() {
    struct Node *temp;

    // If queue is empty
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("%d deleted from queue\n", front->data);

    front = front->next;

    // If queue becomes empty
    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// Display operation
void display() {
    struct Node *temp;

    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    dequeue();

    display();

    enqueue(40);

    display();

    return 0;
}