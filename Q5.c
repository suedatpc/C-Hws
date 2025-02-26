//Recursive linear search
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void createArr(int size, int arr[]);
void printArr(int size, int arr[]);
int recursiveLinearSearch(int size, int arr[],int key, int index);

int main(){
    srand(time(0));
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];
    
    createArr(size, arr);
    printArr(size, arr);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = recursiveLinearSearch(size, arr, key, 0);
    if(result != -1)
        printf("The number %d is found at %d. index. ", key, result);
    else
        printf("The number is not found in the array.");

    return 0;
}


void createArr(int size, int arr[]){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

void printArr(int size, int arr[]){
    printf("The array is: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int recursiveLinearSearch(int size, int arr[],int key, int index){
    if(index >= size)
        return -1;
    
    if(arr[index] == key)
        return index;

    return recursiveLinearSearch(size, arr, key, index + 1);
}