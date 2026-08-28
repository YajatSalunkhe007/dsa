#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue function
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue is Full!" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue." << endl;
    }
}

// Dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is Empty!" << endl;
    }
    else
    {
        cout << queue[front] << " removed from queue." << endl;
        front++;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    enqueue(40);

    return 0;
}