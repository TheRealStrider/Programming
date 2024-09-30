#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX_CHAR 100

struct studentInfo { // Struct to store student information
        char name[MAX_CHAR +1];
        int age;
        char uNum[11];
        bool onCampus;
        bool paidSemester;
};

int main(void) {
    struct studentInfo student1 = {"Frank Summers", 20, "U84018963", false, true};
    struct studentInfo student2 = student1;
    strcpy(student2.name, "Tim Burton");
    student2.onCampus = true;
    student2.paidSemester = false;

    printf("Student 1:\n\tName: %s\n\tAge: %d\n\tU number: %s\n\tLive on Campus: %s\n\tPaid for Semester: %s\n",
           student1.name, student1.age, student1.uNum, (student1.onCampus) ? "Yes" : "No", (student1.paidSemester) ? "Yes": "No");
    printf("Student 2:\n\tName: %s\n\tAge: %d\n\tU number: %s\n\tLive on Campus: %s\n\tPaid for Semester: %s\n",
           student2.name, student2.age, student2.uNum, (student2.onCampus) ? "Yes" : "No", (student2.paidSemester) ? "Yes": "No");
}