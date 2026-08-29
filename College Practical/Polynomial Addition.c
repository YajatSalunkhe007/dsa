/* This is a Program for Polynomial Addition using Linked Lists */


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* createNode(int coeff, int exp)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    return newNode;
}

struct Node* insert(struct Node *head, int coeff, int exp)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = createNode(coeff, exp);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    return head;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);

        if (temp->next != NULL)
        {
            printf(" + ");
        }

        temp = temp->next;
    }

    printf("\n");
}

struct Node* add(struct Node *p, struct Node *q)
{
    struct Node *result = NULL;

    while (p != NULL && q != NULL)
    {
        if (p->exp == q->exp)
        {
            result = insert(result,
                            p->coeff + q->coeff,
                            p->exp);

            p = p->next;
            q = q->next;
        }

        else if (p->exp > q->exp)
        {
            result = insert(result,
                            p->coeff,
                            p->exp);

            p = p->next;
        }

        else
        {
            result = insert(result,
                            q->coeff,
                            q->exp);

            q = q->next;
        }
    }

    while (p != NULL)
    {
        result = insert(result,
                        p->coeff,
                        p->exp);

        p = p->next;
    }

    while (q != NULL)
    {
        result = insert(result,
                        q->coeff,
                        q->exp);

        q = q->next;
    }

    return result;
}

int main()
{
    struct Node *p = NULL;
    struct Node *q = NULL;
    struct Node *result = NULL;

    p = insert(p, 5, 3);
    p = insert(p, 4, 2);
    p = insert(p, 2, 0);

    q = insert(q, 3, 3);
    q = insert(q, 2, 2);
    q = insert(q, 7, 1);
    q = insert(q, 1, 0);

    printf("Polynomial 1: ");
    display(p);

    printf("Polynomial 2: ");
    display(q);

    result = add(p, q);

    printf("Addition: ");
    display(result);

    return 0;
}