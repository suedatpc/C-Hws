//selection sort
#include <stdio.h>

void getNums(int nums[], int *count);
void printArr(int nums[], int *count);
void selectionSort(int nums[], int *count);

int main(){

    int nums[100];
    int count = 0;
    getNums(nums, &count);
    printf("Min to max: ");
    selectionSort(nums, &count);
    printArr(nums, &count);

    return 0;
}

void getNums(int nums[], int *count){
    int num;
    while(1){
        printf("Enter a number to add it to the array and -1 to quit: ");
        scanf("%d", &num);
        if(num != -1){
            nums[*count] = num;
            (*count)++;
        }else{
            break;
        }
            
    }
}

void printArr(int nums[], int *count){
    for(int i = 0; i < *count; i++){
        printf("%d ", nums[i]);
    }
}

void selectionSort(int nums[], int *count){
    for(int i = 0; i < *count; i++){
        int minIndex = i;
        for(int j = i+1; j < *count; j++){
            if(nums[j] < nums[minIndex])
                minIndex = j;
        }
        int temp = nums[i];
        nums[i] = nums[minIndex];
        nums[minIndex] = temp;    
    }
}



