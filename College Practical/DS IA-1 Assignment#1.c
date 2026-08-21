	#include <stdio.h>
    #include <string.h>
    #define SIZE 5

char history[SIZE][50];
int top = -1;

void visit()
{
    if (top == SIZE - 1)
    {
        printf("History is full!\n");
    }
    else
    {
        top++;
        printf("Enter website: ");
        scanf("%s", history[top]);
        printf("Visited: %s\n", history[top]);
    }
}

void back()
{
    if (top == -1)
    {
        printf("No previous page!\n");
    }
    else
    {
        printf("Going back from: %s\n", history[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("History is empty!\n");
    }
    else
    {
        printf("\nBrowser History:\n");

        for (i = top; i >= 0; i--)
        {
            printf("%s\n", history[i]);
        }
    }
}

int main()
{
    int choice;
    do
    {
        printf("\n1. Visit Page");
        printf("\n2. Back");
        printf("\n3. Display History");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            visit();
            break;

        case 2:
            back();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("Invalid choice!");
        }
    } while (choice != 4);
    
    return 0;
}
