#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int flag;
    int data;

    struct Node *next;
    struct Node *down;
};

// Create a node containing data
struct Node* createDataNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->flag = 0;
    newNode->data = value;
    newNode->next = NULL;
    newNode->down = NULL;

    return newNode;
}

// Create a node containing a sublist
struct Node* createSublistNode(struct Node *sublist)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->flag = 1;
    newNode->data = 0;
    newNode->next = NULL;
    newNode->down = sublist;

    return newNode;
}

// Display the GLL
void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        if (temp->flag == 0)
        {
            printf("%d ", temp->data);
        }
        else
        {
            printf("( ");
            display(temp->down);
            printf(") ");
        }

        temp = temp->next;
    }
}

int main()
{
    struct Node *head;

    // Create sublist: 20 -> 30
    struct Node *sublist;

    sublist = createDataNode(20);
    sublist->next = createDataNode(30);

    // Create main list: 10 -> sublist -> 40
    head = createDataNode(10);

    head->next = createSublistNode(sublist);

    head->next->next = createDataNode(40);

    printf("Generalized Linked List: ");

    display(head);

    return 0;
}