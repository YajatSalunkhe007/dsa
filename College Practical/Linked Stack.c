/* This Program helps you understand Stack using Linked Lists.*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

// PUSH operation
void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    printf("%d pushed into stack\n", value);
}

// POP operation
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;

    printf("%d popped from stack\n", top->data);

    top = top->next;

    free(temp);
}

// DISPLAY operation
void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }

    temp = top;

    printf("Stack elements are:\n");

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// MAIN function
int main()
{
    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}