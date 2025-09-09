#ifndef STYDENT_H
#define STYDENT_H

#define FILE_NAME "students.dat"
#define BACKUP_FILE "backup_students.dat"

#define ssssss  12313132313
typedef struct {
    int id;
    char name[50];
    int age;
    int grade;
} Student;


// Function prototypes
void Add_Stydent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void sortStudentsByGrade();
void countStudents();
void filterStudentsByGradeRange() ;
void displayTopPerformer() ;
void restoreRecords();
void backupRecords() ;
#endif /*STYDENT_H*/