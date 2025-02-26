#include <stdio.h>

int main(){
    FILE *file = fopen("Q10.txt", "w");
    FILE *averages = fopen("Q10.1.txt", "w");
    char name[20];
    float midterm, final, average;

    for(int i = 0; i < 3; i++){
        printf("Enter the name of the student: ");
        scanf("%s", name);
        printf("Enter the midterm and final note of the student: ");
        scanf("%f %f", &midterm, &final);
        average = (midterm + final) / 2;
        fprintf(file, "%s\t%.2f\t%.2f ---> %.2f\n", name,midterm,final,average);
        fprintf(averages, "%.2f\n", average);

    }
    fclose(file);
    return 0;
}