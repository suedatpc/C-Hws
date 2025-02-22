//binary Search
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void getArr(int arr[] ,int size);
void printArr(int arr[] ,int size);
void bubbleSort(int arr[] ,int size);
void binarySearch(int arr[] ,int size, int key);


int main(){
    int size,key;
    srand(time(0));

    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    getArr(arr, size);
    printf("Before sorting: ");
    printArr(arr, size);

    bubbleSort(arr, size);
    printf("After sorting: ");
    printArr(arr, size);

    printf("Enter the key to search: ");
    scanf("%d", &key);

    binarySearch(arr, size, key);

    return 0;
}

void getArr(int arr[] ,int size){   
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

void printArr(int arr[] ,int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void binarySearch(int arr[], int size, int key){
    int low = 0, high = size - 1, mid, iteration = 0;
    while(low <= high){
        iteration++;
        mid = (low + high) / 2;
        if(arr[mid] == key){
            printf("Key found at index %d\n", mid);
            printf("Number of iterations: %d\n", iteration);
            return;
        }else if(arr[mid] < key){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    printf("Key not found in the array.\n");
}
