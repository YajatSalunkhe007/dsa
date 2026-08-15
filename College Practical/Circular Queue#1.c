#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue Function
void enqueue(int value)
{
    // Check if queue is full
    if ((rear + 1) % SIZE == front)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        // First element
        if (front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        queue[rear] = value;

        printf("%d inserted\n", value);
    }
}

// Dequeue Function
void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        printf("%d deleted\n", queue[front]);

        // Last element removed
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

// Display Function
void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        int i = front;

        printf("Queue Elements: ");

        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        printf("\n");
    }
}

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

        switch(choice)
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

    } while(choice != 4);

    return 0;
}