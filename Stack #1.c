#include <stdio.h>
#include <conio.h>

int stk[5], top = -1;

void push();
void pop();
void display();

void main()
{
    
    int ch;
    do
    {
        printf("\nEnter 1.Push  2.Pop  3.Display : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            default:
                printf("Wrong Choice");
        }

        printf("\nPress 1 to continue: ");
        scanf("%d", &ch);

    } while(ch == 1);

    getch();  /*the getch() function which waits until
                the user presses a key before closing the program.*/
                /*of the user enter 1, the loop continues. but if the user enters 
                anything other than 1 then loop ends*/
}

void push()
{
    printf("This is Push Function");
}

void pop()
{
    printf("This is Pop Function");
}

void display()
{
    printf("This is Display Function");
}