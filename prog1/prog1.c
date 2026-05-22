#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int roll;
    char name[30];
    float marks;
};


void addRecords()
{
    FILE *fp;
    struct Student s;
    int n, i;

    fp = fopen("student.dat", "wb");

    if (fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    printf("Enter number of records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d\n", i + 1);

        printf("Roll: ");
        scanf("%d", &s.roll);

        printf("Name: ");
        scanf("%s", s.name);

        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(s), 1, fp);
    }

    fclose(fp);
    printf("\nRecords stored successfully.\n");
}

// Function to display mth record using fseek
void displayMthRecord(int m)
{
    FILE *fp;
    struct Student s;

    fp = fopen("student.dat", "rb");

    if (fp == NULL)
    {
        printf("File cannot be opened!\n");
        return;
    }

    // Move pointer to mth record
    fseek(fp, (m - 1) * sizeof(s), SEEK_SET);

    if (fread(&s, sizeof(s), 1, fp))
    {
        printf("\nRecord %d\n", m);
        printf("Roll  : %d\n", s.roll);
        printf("Name  : %s\n", s.name);
        printf("Marks : %.2f\n", s.marks);
    }
    else
    {
        printf("Record not found!\n");
    }

    fclose(fp);
}

// Function to delete a record
void deleteRecord(int rollNo)
{
    FILE *fp, *temp;
    struct Student s;
    int found = 0;

    fp = fopen("student.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL || temp == NULL)
    {
        printf("File error!\n");
        return;
    }

    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll != rollNo)
        {
            fwrite(&s, sizeof(s), 1, temp);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("Record deleted successfully.\n");
    else
        printf("Record not found.\n");
}

// Main function
int main()
{
    int m, roll;

    addRecords();

    printf("\nEnter record number to display: ");
    scanf("%d", &m);

    displayMthRecord(m);

    printf("\nEnter roll number to delete: ");
    scanf("%d", &roll);

    deleteRecord(roll);

    return 0;
}