#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Student structure
struct Student
{
    int rollNo;
    char name[50];
    int age;
    char course[50];
    float marks;
};

// Student array
struct Student students[MAX_STUDENTS] = {
    {1, "Divya Chauhan", 19, "BCA", 80},
    {2, "Raman", 19, "BCA", 81},
    {3, "Naman", 19, "BCA", 82},
    {4, "Rani", 19, "BCA", 83},
    {5, "Ram", 19, "BCA", 84},
    {6, "Nitish", 19, "BCA", 85},
    {7, "Suhan", 19, "BCA", 86},
    {8, "Suhani", 19, "BCA", 87},
    {9, "Dipika", 19, "BCA", 88},
    {10, "Dipali", 19, "BCA", 89}};

int count = 10;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int main()
{

    int choice;

    while (1)
    {

        printf("\n============================================\n");
        printf("       STUDENT MANAGEMENT SYSTEM\n");
        printf("============================================\n");

        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("============================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            addStudent();
            break;

        case 2:
            displayStudents();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            printf("\nThank you for using Student Management System!\n");
            exit(0);

        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// ============================================
// ADD STUDENT
// ============================================

void addStudent()
{

    if (count >= MAX_STUDENTS)
    {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\n----------- ADD STUDENT -----------\n");

    printf("Enter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Age: ");
    scanf("%d", &students[count].age);

    printf("Enter Course: ");
    scanf(" %[^\n]", students[count].course);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;

    printf("\nStudent added successfully!\n");
}

// ============================================
// DISPLAY ALL STUDENTS
// ============================================

void displayStudents()
{

    if (count == 0)
    {
        printf("\nNo students found!\n");
        return;
    }

    printf("\n================ STUDENT LIST ================\n");

    printf("%-10s %-20s %-10s %-15s %-10s\n",
           "Roll No", "Name", "Age", "Course", "Marks");

    printf("------------------------------------------------------------\n");

    for (int i = 0; i < count; i++)
    {

        printf("%-10d %-20s %-10d %-15s %-10.2f\n",
               students[i].rollNo,
               students[i].name,
               students[i].age,
               students[i].course,
               students[i].marks);
    }

    printf("============================================================\n");
}

// ============================================
// SEARCH STUDENT
// ============================================

void searchStudent()
{

    int rollNo;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++)
    {

        if (students[i].rollNo == rollNo)
        {

            printf("\n----------- STUDENT FOUND -----------\n");

            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s\n", students[i].name);
            printf("Age         : %d\n", students[i].age);
            printf("Course      : %s\n", students[i].course);
            printf("Marks       : %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent with Roll Number %d not found!\n", rollNo);
    }
}

// ============================================
// UPDATE STUDENT
// ============================================

void updateStudent()
{

    int rollNo;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++)
    {

        if (students[i].rollNo == rollNo)
        {

            printf("\nStudent found!\n");

            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Age: ");
            scanf("%d", &students[i].age);

            printf("Enter New Course: ");
            scanf(" %[^\n]", students[i].course);

            printf("Enter New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}

// ============================================
// DELETE STUDENT
// ============================================

void deleteStudent()
{

    int rollNo;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++)
    {

        if (students[i].rollNo == rollNo)
        {

            // Shift students one position to the left
            for (int j = i; j < count - 1; j++)
            {

                students[j] = students[j + 1];
            }

            count--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nStudent not found!\n");
    }
}