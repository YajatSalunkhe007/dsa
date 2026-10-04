#include <stdio.h>
#define SIZE 10
struct Student
{
    int rollNo;
    char name[30];
};

/* Hash function */
int hashFunction(int rollNo)
{
    return rollNo % SIZE;
}

/* Insert record into file */
void insertRecord()
{
    FILE *fp;
    struct Student s;
    int position;
    fp = fopen("students.dat", "r+b");
    if (fp == NULL)
    {
        fp = fopen("students.dat", "w+b");
    }

    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf("%s", s.name);
    position = hashFunction(s.rollNo);
    fseek(fp, position * sizeof(struct Student), SEEK_SET);
    fwrite(&s, sizeof(struct Student), 1, fp);
    printf("Record inserted at position %d.\n", position);
    fclose(fp);
}

/* Search record using hashing */
void searchRecord()
{
    FILE *fp;
    struct Student s;
    int rollNo;
    int position;
    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("File does not exist.\n");
        return;
    }

    printf("Enter Roll Number to search: ");
    scanf("%d", &rollNo);

    position = hashFunction(rollNo);

    fseek(fp, position * sizeof(struct Student), SEEK_SET);
    fread(&s, sizeof(struct Student), 1, fp);

    if (s.rollNo == rollNo)
    {
        printf("\nRecord Found!\n");
        printf("Roll Number: %d\n", s.rollNo);
        printf("Name: %s\n", s.name);
    }
    else
    {
        printf("Record not found.\n");
    }

    fclose(fp);
}

/* Display all records */
void displayRecords()
{
    FILE *fp;
    struct Student s;
    int i;
    fp = fopen("students.dat", "rb");

    if (fp == NULL)
    {
        printf("File does not exist.\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    for (i = 0; i < SIZE; i++)
    {
        fseek(fp, i * sizeof(struct Student), SEEK_SET);
        if (fread(&s, sizeof(struct Student), 1, fp) == 1)
        {
            if (s.rollNo != 0)
            {
                printf("Position %d -> Roll No: %d, Name: %s\n",
                       i, s.rollNo, s.name);
            }
        }
    }
    fclose(fp);
}

int main()
{
    int choice;
    do
    {
        printf("\n===== FILE ORGANIZATION USING HASHING =====\n");
        printf("1. Insert Record\n");
        printf("2. Search Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertRecord();
                break;

            case 2:
                searchRecord();
                break;

            case 3:
                displayRecords();
                break;

                
            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
    return 0;
}