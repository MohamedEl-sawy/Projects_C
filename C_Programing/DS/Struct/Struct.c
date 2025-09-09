#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student_info {
    char Student_Name[20];
    float Student_GBA;
    unsigned short Student_ID;
} Student_t;

Student_t Ahmed;

void get_std_data(Student_t *Student)
{
    printf("Enter std name: ");
    scanf("%s", Student->Student_Name);
    printf("Enter Student GBA: ");
    if (scanf("%f", &(Student->Student_GBA)) != 1) {
        printf("Invalid input for GBA.\n");
        exit(EXIT_FAILURE);
    }
    printf("Enter Student ID: ");
    if (scanf("%hu", &(Student->Student_ID)) != 1) {
        printf("Invalid input for ID.\n");
        exit(EXIT_FAILURE);
    }
}

void Print_std_data(Student_t *Ahmed)
{
    printf("\nStudent name: %s\n", Ahmed->Student_Name);
    printf("GBA: %.2f\n", Ahmed->Student_GBA);
    printf("ID: %hu\n", Ahmed->Student_ID);
}

int main()
{
    get_std_data(&Ahmed);
    Print_std_data(&Ahmed);

    return 0;
}
