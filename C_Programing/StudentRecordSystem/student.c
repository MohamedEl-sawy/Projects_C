#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
// void Add_Stydent();
// void viewStudents();
// void searchStudent();
// void updateStudent();
// void deleteStudent();

// Function to add a new student record to the file
void Add_Stydent()
{
    FILE *file = fopen(FILE_NAME, "ab"); // Open file in append binary mode
    if (!file) {
        perror("Unable to open file"); // Display error if file cannot be opened
        return;
    }

    Student student;
    printf("Enter Stydent ID: ");
    scanf("%d", &student.id);
    printf("Enter Stydent Name: ");
    getchar(); // This will consume the newline character left in the buffer
    scanf("%[^\n]", student.name);// To read a string with spaces
    printf("Enter Stydent Age: ");
    scanf("%d", &student.age);
    printf("Enter Stydent Grade: ");
    scanf("%d", &student.grade);

    fwrite(&student, sizeof(Student), 1, file); // Write the student data to the file
    fclose(file); // Close the file
    printf("Student added successfully!\n");
}

// View all student records
void viewStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Student student;
    printf("\n=== All Students ===\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Age: %d, Grade: %d\n", 
               student.id, student.name, student.age, student.grade);
    }
    fclose(file);
}
// Search for a student by ID
void searchStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int searchId;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == searchId) {
            printf("ID: %d, Name: %s, Age: %d, Grade: %.2f\n", 
                   student.id, student.name, student.age, student.grade);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", searchId);
    }
    fclose(file);
}

// Update a student record
void updateStudent()
{
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int updateId;
    printf("Enter Student ID to update: ");
    scanf("%d", &updateId);

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == updateId) {
            printf("Enter new details:\n");
            printf("Enter Student Name: ");
            scanf(" %[^\n]", student.name);
            printf("Enter Student Age: ");
            scanf("%d", &student.age);
            printf("Enter Student Grade: ");
            scanf("%f", &student.grade);

            fseek(file, -sizeof(Student), SEEK_CUR); // Move file pointer back
            fwrite(&student, sizeof(Student), 1, file);
            printf("Student record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", updateId);
    }
    fclose(file);
}

void deleteStudent()
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Unable to create temporary file");
        fclose(file);
        return;
    }
    int deleteId;
    printf("Enter Student ID to delete: ");
    scanf("%d", &deleteId);

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == deleteId) {
            found = 1;
        } else {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }
    fclose(file);
    fclose(tempFile);
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);
    if (found) {
        printf("Student record deleted successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", deleteId);
    }
}

// Sort students by grade in descending order
void sortStudentsByGrade()
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }
    Student students[100];
    int count = 0;
    while (fread(&students[count], sizeof(Student), 1, file))
    {
        count++;
    }
    fclose(file);

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (students[j].grade < students[j + 1].grade)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("\n=== Students Sorted by Grade ===\n");
    for (int i = 0; i < count; i++)
    {
        printf("ID: %d, Name: %s, Age: %d, Grade: %d\n",
               students[i].id, students[i].name, students[i].age, students[i].grade);
    }

}

// Count total students
void countStudents() 
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int count = 0;
    Student student;
    while (fread(&student, sizeof(Student), 1, file)) 
    {
        count++;
    }
    fclose(file);

    printf("Total number of students: %d\n", count);
}

// Filter students by grade range
void filterStudentsByGradeRange() 
{
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    float minGrade, maxGrade;
    printf("Enter minimum grade: ");
    scanf("%f", &minGrade);
    printf("Enter maximum grade: ");
    scanf("%f", &maxGrade);

    Student student;
    printf("\n=== Students in Grade Range ===\n");
    while (fread(&student, sizeof(Student), 1, file)) 
    {
        if (student.grade >= minGrade && student.grade <= maxGrade) 
        {
            printf("ID: %d, Name: %s, Age: %d, Grade: %d\n",
                   student.id, student.name, student.age, student.grade);
        }
    }
    fclose(file);
}

// Backup records
void backupRecords() {
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *backupFile = fopen(BACKUP_FILE, "wb");
    if (!file || !backupFile) {
        perror("Unable to open file");
        return;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, file)) {
        fwrite(&student, sizeof(Student), 1, backupFile);
    }

    fclose(file);
    fclose(backupFile);
    printf("Backup created successfully!\n");
}

// Restore records
void restoreRecords() {
    FILE *backupFile = fopen(BACKUP_FILE, "rb");
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file || !backupFile) {
        perror("Unable to open file");
        return;
    }

    Student student;
    while (fread(&student, sizeof(Student), 1, backupFile)) {
        fwrite(&student, sizeof(Student), 1, file);
    }

    fclose(file);
    fclose(backupFile);
    printf("Records restored successfully!\n");
}


// Display top performer
void displayTopPerformer() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Student topStudent;
    int found = 0;
    Student student;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (!found || student.grade > topStudent.grade) {
            topStudent = student;
            found = 1;
        }
    }
    fclose(file);

    if (found) {
        printf("\n=== Top Performer ===\n");
        printf("ID: %d, Name: %s, Age: %d, Grade: %d\n",
               topStudent.id, topStudent.name, topStudent.age, topStudent.grade);
    } else {
        printf("No records found.\n");
    }
}