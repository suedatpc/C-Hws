#include <stdio.h>

int main(){
    FILE *file;
    int num;
    file = fopen("Q7.txt", "w");
    for(int i = 0; i < 5; i++){
        scanf("%d", &num);
        fprintf(file, "%d\n", num);
    }
    fclose(file);

    return 0;
}