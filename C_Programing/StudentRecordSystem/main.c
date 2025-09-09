#include <stdio.h>
#include "student.c"

void menu(); // Function prototypes

int main()
{
    menu(); 
    return 0;
}

// Menu function
void menu() 
{
    int choice;
    do {
        printf("\n=== Student Record System ===\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search for a Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by Grade\n");
        printf("7. Count Total Students\n");
        printf("8. Filter Students by Grade Range\n");
        printf("9. Backup Records\n");
        printf("10. Restore Records\n");
        printf("11. Display Top Performer\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                Add_Stydent();
                break;
            case 2: 
                viewStudents(); 
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
                sortStudentsByGrade();
                break;
            case 7: 
                countStudents(); 
                break;
            case 8:
                filterStudentsByGradeRange(); 
                break;
            case 9:
                backupRecords(); 
                break;
            case 10: 
                restoreRecords(); 
                break;
            case 11:
                displayTopPerformer();
                break;
            case 12: 
                printf("Exiting the system.\n");
                break;
            default: 
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 12);
    
}