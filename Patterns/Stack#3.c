#include <stdio.h> 
#define SIZE 5 /* #define is a macro. it replaces every occurence of SIZE 
                  with 5 before compilation. so the compiler directly sees
                  " int stack [5] " instead of "int stack [SIZE]".
                  
                  and we wrote "#define SIZE 5" instead of just "int stack[5]"
                  because if later you want to change the size of the stack
                  to 100, we can  just change the value of SIZE, "#define 
                  SIZE 100". */
int stack[SIZE]; 
int top = -1; /* we write -1 because array indexing starts from 0 and if there
                 are no elements, there is no valid index.*/

// Push Function 

void push(int value) 
{ 
    if(top == SIZE - 1) 
    { 
        printf("Stack Overflow\n"); 
    } 
    else 
    { 
        top++; 
        stack[top] = value; 
        printf("%d inserted\n", value); 
    } 
} 

// Pop Function

void pop() 
{ 
    if(top == -1) 
    { 
        printf("Stack Underflow\n"); 
    } 
    else 
    { 
        printf("%d removed\n", stack[top]); 
        top--; 
    } 
} 

// Peek Function 
// This function is used to see the top element.
void peek() 
{ 
   if(top == -1) 
    { 
        printf("Stack is Empty\n"); 
    } 
    else 
    { 
        printf("Top Element = %d\n", stack[top]); 
    } 
} 
 
// Display Function 

void display() 
{ 
    if(top == -1) 
    { 
        printf("Stack is Empty\n"); 
    } 
    else 
    { 
        printf("Stack Elements:\n"); 
        for(int i = top; i >= 0; i--) 
        { 
            printf("%d ", stack[i]); 
        } 
        printf("\n"); 
    } 
} 
 
int main() 
{ 
    push(10); 
    push(20); 
    push(30); 
 
    display(); 
    peek(); 
    pop(); 
display(); 
return 0; 
}