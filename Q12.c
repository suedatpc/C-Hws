#include <stdio.h>

int main(){
    FILE *data = fopen("Q10.txt", "r");
    FILE *finalFile = fopen("Q12.txt", "w");

    char name[20];
    float midterm, final, average;

    while(fscanf(data, "%s %f %f ---> %f", name, &midterm, &final, &average) != EOF){
        fprintf(finalFile, "%s %.2f %.2f %.2f ", name, midterm, final, average);
        
        if(average >= 0 && average <= 44){   
            fprintf(finalFile, "FF\t(FAILED)\n");   
        }else if(average >= 45 && average <= 54){      
            fprintf(finalFile, "DD\t(FAILED)\n");
        }else if(average >= 55 && average <= 69){
            fprintf(finalFile, "CC\t(PASSED)\n");
        }else if(average >= 70 && average <= 84){
            fprintf(finalFile, "BB\t(PASSED)\n");
        }else{
            fprintf(finalFile, "AA\t(PASSED)\n");
        } 
    }

    fclose(data);
    fclose(finalFile);
    return 0;
}