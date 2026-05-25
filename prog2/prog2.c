#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure definition
struct Student
{
    int id;
    char name[50];
    float marks;
};

// Function to write array of structures to file
void writeRecords(const char *filename, struct Student s[], int n)
{
    FILE *fp = fopen(filename, "w");

    if (fp == NULL)
    {
        printf("File open error\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(fp, "%d %s %.2f\n",
                s[i].id,
                s[i].name,
                s[i].marks);
    }

    fclose(fp);
}

// Function to create array of seek positions
int createSeekPositions(const char *filename, long positions[])
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File open error\n");
        return 0;
    }

    int count = 0;
    char line[200];

    while (1)
    {
        long pos = ftell(fp);

        if (fgets(line, sizeof(line), fp) == NULL)
            break;

        positions[count++] = pos;
    }

    fclose(fp);

    return count;
}

// Function to display record using seek position
void displayRecord(const char *filename, long position)
{
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File open error\n");
        return;
    }

    fseek(fp, position, SEEK_SET);

    struct Student s;

    fscanf(fp, "%d %s %f",
           &s.id,
           s.name,
           &s.marks);

    printf("Record Found:\n");
    printf("ID    : %d\n", s.id);
    printf("Name  : %s\n", s.name);
    printf("Marks : %.2f\n", s.marks);

    fclose(fp);
}

int main()
{
    struct Student students[] =
    {
        {101, "Arun", 89.5},
        {102, "Bala", 76.0},
        {103, "Charan", 91.2},
        {104, "Deepak", 67.8}
    };

    int n = sizeof(students) / sizeof(students[0]);

    long positions[MAX];

    // Write records
    writeRecords("students.txt", students, n);

    // Create seek positions
    int total = createSeekPositions("students.txt", positions);

    printf("Seek Positions:\n");

    for (int i = 0; i < total; i++)
    {
        printf("Record %d -> Position %ld\n",
               i + 1,
               positions[i]);
    }

    printf("\n");

    // Display a particular record
    int choice;

    printf("Enter record number to display: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= total)
    {
        displayRecord("students.txt",
                      positions[choice - 1]);
    }
    else
    {
        printf("Invalid record number\n");
    }

    return 0;
}