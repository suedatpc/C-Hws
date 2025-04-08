#include <stdio.h>

struct Student{
    int no;
    float midterm;
    float final;
    float average;
};

void calculateScore(int i, struct Student s[]){
    s[i].average = (s[i].midterm + s[i].final) / 2;
}

int main(){
    float classAverage = 0;
    struct Student s[3];

    for(int i = 0; i < 3; i++){
        printf("Enter the student no, midterm and final notes for the student: ");
        scanf("%d %f %f", &s[i].no, &s[i].midterm, &s[i].final);
    }

    printf("Student NO\tMidterm\tFinal\tGPA\n");

    for(int i = 0; i < 3; i++){
        calculateScore(i, s);
        printf("%d\t\t%.2f\t%.2f\t%.2f\n", s[i].no, s[i].midterm, s[i].final, s[i].average);
        classAverage += s[i].average;
    }

    classAverage /= 3;
    printf("\nThe average of the class is: %f", classAverage);

    

    return 0;
}