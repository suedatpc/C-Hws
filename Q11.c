#include <stdio.h>

int main(){
    FILE *file = fopen("Q8.txt", "r");
    FILE *evenNums = fopen("Q11even.txt", "w");
    FILE *oddNums = fopen("Q11odd.txt", "w");

    int num;
    while (fscanf(file, "%d", &num) != EOF){
        if(num % 2 == 0)
            fprintf(evenNums, "%d\n", num);
        else
            fprintf(oddNums, "%d\n", num);
    
    }   
    
    fclose(file);
    fclose(evenNums);
    fclose(oddNums);
    return 0;
}