//linear search
#include <stdio.h>

void printArr(int arr[], int *count);
void getNums(int nums[], int *count);
void searchNum(int arr[], int *iteration, int *count);


int main(){
    int count = 0;
    int numbers[100];
    int iteration = 0;
    getNums(numbers, &count);
    printf("\nThe Array: ");
    printArr(numbers, &count);
    printf("\n");
    searchNum(numbers, &iteration, &count);


    return 0;
}


void printArr(int arr[], int *count){
    for(int i = 0; i < *count; i++)
        printf("%d, ", arr[i]);
}

void getNums(int nums[], int *count){
    int num;
    while(1){
        printf("Enter a number or -1 to quit: ");
        scanf("%d", &num);
        if(num != -1){
            nums[*count] = num;
            (*count)++;
        }else{
            break;
        }
    }
}

void searchNum(int arr[], int *iteration, int *count){
    int num, found = 0;
    printf("\nEnter the number you want to find: ");
    scanf("%d", &num);

    for(int i = 0; i < *count; i++){
        (*iteration)++;
        if(arr[i] == num){
            printf("\nThe number was found at %d. iteration\n", *iteration);
            found = 1;
            break;
        }        
    }
    if(found == 0)
        printf("\nThe number was not found."); 
}

