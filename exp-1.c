//To demonstrate the use of array, structure, and union along with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

union U 
{
    int roll;
    float percentage;
};

struct Student
 {
    char name[20];
    int marks[3];  
    union U data;  
};

int main()
 {
    int n, i, j;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student *s = (struct Student *)malloc(n * sizeof(struct Student));

    for (i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);

        printf("Enter marks in 3 subjects: ");
        for (j = 0; j < 3; j++)
            scanf("%d", &s[i].marks[j]);

        printf("Enter roll number: ");
        scanf("%d", &s[i].data.roll);
    }

    printf("\n--- Student Details ---\n");
    for (i = 0; i < n; i++) {
        printf("\nName: %s\n", s[i].name);
        printf("Marks: ");
        for (j = 0; j < 3; j++)
            printf("%d ", s[i].marks[j]);
        printf("\nRoll Number: %d\n", s[i].data.roll);
    }

    free(s);
    return 0;
}


