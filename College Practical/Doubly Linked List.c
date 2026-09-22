#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for an employee node
struct Employee
{
    int id;
    char name[50];
    char designation[50];
    float salary;

    struct Employee *prev;
    struct Employee *next;
};

// Head pointer
struct Employee *head = NULL;

// Function to insert an employee
void insert()
{
    struct Employee *newNode;
    
    newNode = (struct Employee *)malloc(sizeof(struct Employee));

    printf("\nEnter Employee ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Designation: ");
    scanf(" %[^\n]", newNode->designation);

    printf("Enter Salary: ");
    scanf("%f", &newNode->salary);

    newNode->prev = NULL;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Employee *temp = head;

        // Go to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("\nEmployee inserted successfully!\n");
}

// Function to delete an employee by ID
void delete()
{
    int id;
    struct Employee *temp;

    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    temp = head;

    // Search for the employee
    while (temp != NULL && temp->id != id)
    {
        temp = temp->next;
    }

    // Employee not found
    if (temp == NULL)
    {
        printf("\nEmployee not found!\n");
        return;
    }

    // If deleting the first node
    if (temp == head)
    {
        head = temp->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);

    printf("\nEmployee deleted successfully!\n");
}

// Function to search an employee by ID
void search()
{
    int id;
    struct Employee *temp;

    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("\nEmployee Found!\n");
            printf("-----------------------------\n");
            printf("Employee ID   : %d\n", temp->id);
            printf("Name          : %s\n", temp->name);
            printf("Designation   : %s\n", temp->designation);
            printf("Salary        : %.2f\n", temp->salary);
            printf("-----------------------------\n");

            return;
        }

        temp = temp->next;
    }

    printf("\nEmployee not found!\n");
}

// Function to display all employees
void display()
{
    struct Employee *temp;

    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    temp = head;

    printf("\n========== Employee List ==========\n");

    while (temp != NULL)
    {
        printf("\nEmployee ID   : %d", temp->id);
        printf("\nName          : %s", temp->name);
        printf("\nDesignation   : %s", temp->designation);
        printf("\nSalary        : %.2f", temp->salary);
        printf("\n-----------------------------------");

        temp = temp->next;
    }

    printf("\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n\n===== EMPLOYEE DOUBLY LINKED LIST =====");
        printf("\n1. Insert Employee");
        printf("\n2. Delete Employee");
        printf("\n3. Search Employee");
        printf("\n4. Display Employees");
        printf("\n5. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                search();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProgram ended.\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}