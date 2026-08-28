#include <iostream>
using namespace std;

#define SIZE 10

int stackArr[SIZE];

int top1 = -1;
int top2 = SIZE;

void push1(int value)
{
    if (top1 + 1 == top2)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top1++;
        stackArr[top1] = value;
    }
}

void push2(int value)
{
    if (top1 + 1 == top2)
    {
        cout << "Stack Overflow!" << endl;
    }
    else
    {
        top2--;
        stackArr[top2] = value;
    }
}

void pop1()
{
    if (top1 == -1)
    {
        cout << "Stack 1 is Empty!" << endl;
    }
    else
    {
        cout << "Deleted: " << stackArr[top1] << endl;
        top1--;
    }
}

void pop2()
{
    if (top2 == SIZE)
    {
        cout << "Stack 2 is Empty!" << endl;
    }
    else
    {
        cout << "Deleted: " << stackArr[top2] << endl;
        top2++;
    }
}

void display1()
{
    if (top1 == -1)
    {
        cout << "Stack 1 is Empty!" << endl;
    }
    else
    {
        cout << "Stack 1: ";

        for (int i = top1; i >= 0; i--)
        {
            cout << stackArr[i] << " ";
        }

        cout << endl;
    }
}

void display2()
{
    if (top2 == SIZE)
    {
        cout << "Stack 2 is Empty!" << endl;
    }
    else
    {
        cout << "Stack 2: ";

        for (int i = top2; i < SIZE; i++)
        {
            cout << stackArr[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    push1(10);
    push1(20);
    push1(30);

    push2(100);
    push2(200);
    push2(300);

    display1();
    display2();

    pop1();
    pop2();

    display1();
    display2();

    return 0;
}