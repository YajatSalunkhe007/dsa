#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;
    if (x == '*' || x == '/' || x == '%')
        return 2;
    if (x == '+' || x == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[])
{
    char postfix[100];
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        // If operand, add it to postfix
        if (isalnum(x))
        {
            postfix[j++] = x;
        }

        // If opening parenthesis, push it
        else if (x == '(')
        {
            push(x);
        }

        // If closing parenthesis
        else if (x == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            pop();   // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(x))
            {
                postfix[j++] = pop();
            }

            push(x);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);
}

int main()
{
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);

    return 0;
}