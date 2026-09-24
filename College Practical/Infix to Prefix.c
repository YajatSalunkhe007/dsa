#include <stdio.h>
#include <string.h>
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

void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[])
{
    char prefix[100];
    int i, j = 0;
    char x;

    // Step 1: Reverse infix
    reverse(infix);

    // Step 2: Change brackets
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';

        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert to postfix
    top = -1;

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        if (isalnum(x))
        {
            prefix[j++] = x;
        }

        else if (x == '(')
        {
            push(x);
        }

        else if (x == ')')
        {
            while (stack[top] != '(')
            {
                prefix[j++] = pop();
            }

            pop();
        }

        else
        {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(x))
            {
                prefix[j++] = pop();
            }

            push(x);
        }
    }

    while (top != -1)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    // Step 4: Reverse postfix to get prefix
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);
}

int main()
{
    char infix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix);

    return 0;
}