#include <stdio.h>

int main(){
    FILE *file = fopen("Q9.txt", "w");
    char name[20];
    int midterm, final;

    for(int i = 0; i < 5; i++){
        printf("Enter the name of the student: ");
        scanf("%s", name);
        printf("Enter the midterm and final note of the student: ");
        scanf("%d %d", &midterm, &final);

        fprintf(file, "%s\t%d\t%d\n", name,midterm,final);
    }

    fclose(file);
    return 0;
}