#include <stdio.h>
#include <string.h>
char stk[5][20]; /* this means that this 2D character array contains 5 rows and 
                    20 columns. This implies that: - 
                    1. Maximum 5 student names
                    2. Each name can contain 19 characters
                    3. Last character is reserved for '\0' (null character)*/

int top = -1;

void push();
void pop();
void display();

int main()
{
int ch;
do
{

    printf("\n1. Push\n2. Pop\n3. Display\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: push();
         break;

        case 2: pop();
         break;

        case 3: display();
         break;

        default: printf("Wrong choice");
    }

    printf("\nPress 1 to continue: ");
    scanf("%d",&ch);

}while(ch==1);
return 0;
}

void push(){

if(top==4) /* why 4, because is it based on 0-based indexing.*/
{
    printf("Stack Overflow");
}
else

{
    top++;
    printf("Enter student name: ");
    scanf("%s",stk[top]);
    printf("This is Push Function");
}
}
void pop()
{
if(top==-1)
{
    printf("Stack Underflow");
}

else

{

    printf("Deleted Student: %s",stk[top]);
    top--;
    printf("\nThis is Pop Function");

}

}

void display()
{
int i;
if(top==-1)
{
    printf("Stack is Empty");
}
else
{
    printf("Students in Stack:\n");
    for(i=top;i>=0;i--){
        printf("%s\n",stk[i]);
    }

    printf("This is Display Function");

}

} 