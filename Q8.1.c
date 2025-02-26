#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int findMax(int arr[], int size){
    int max = arr[0];
    for(int i = 0; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int main(){
    int nums[5][10];
    srand(time(0));
    FILE *file = fopen("Q8.txt", "w");

    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        return 1;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 5; j++){
            nums[i][j] = rand() % 100;
            fprintf(file, "%d ", nums[i][j]);
        }
        int max = findMax(nums[i], 5);
        fprintf(file, "--> %d\n", max);

    }

    fclose(file);
    return 0;
}