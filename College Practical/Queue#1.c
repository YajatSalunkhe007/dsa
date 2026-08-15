#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue Function
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("%d inserted\n", value);
    }
}

// Dequeue Function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted\n", queue[front]);
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

// Display Function
void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue Elements: ");

        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

// Main Function
int main()
{
    int choice, value;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Program Ended\n");
                break;

            default:
                printf("Invalid Choice\n");
        }

    } while (choice != 4);

    return 0;
}