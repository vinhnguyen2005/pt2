#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float average(float lab, float pt, float as, float pe, float fe) {
    return 0.1 * (lab + pt + as) + 0.4 * pe + 0.3 * fe;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    getchar();  

    char StudentId[n][25];
    char name[n][30];
    float lab, pt, as, pe, fe, avg;

    for (int i = 0; i < n; i++) {
        printf("\nEnter information for student %d:\n", i + 1);
        
        printf("Student ID: ");
        fgets(StudentId[i], sizeof(StudentId[i]), stdin);

        printf("\nName: ");
        fgets(name[i], sizeof(name[i]), stdin);

        printf("Lab score: ");
        scanf("%f", &lab);
        printf("PT score: ");
        scanf("%f", &pt);
        printf("AS score: ");
        scanf("%f", &as);
        printf("PE score: ");
        scanf("%f", &pe);
        printf("FE score: ");
        scanf("%f", &fe);

        avg = average(lab, pt, as, pe, fe);

        printf("Average point of student %d: %.2f\n", i + 1, avg);
    }

    return 0;
}
