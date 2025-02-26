#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int num;
    srand(time(0));

    FILE *file = fopen("Q8.txt", "w");

    if (file == NULL){
        printf("Dosya açılamadı!\n");
        return 1;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            num = rand() % 100;
            fprintf(file, "%d ", num);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}