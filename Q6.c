//recursive binary search
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void createArr(int size, int arr[]);
void printArr(int size, int arr[]);
void selectionSort(int size, int arr[]);
int recursiveBinarySearch(int arr[], int key, int low, int high);

int main(){
    srand(time(0));
    int size, key;
    int arr[size];
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    createArr(size, arr);
    printf("The array is: ");
    printArr(size, arr);
    selectionSort(size, arr);
    printArr(size, arr);

    printf("Enter a key to search: ");
    scanf("%d", &key);    

    int result = recursiveBinarySearch(arr, key, 0, size - 1);
    if(result != - 1)
        printf("The number %d is found at index %d. ", key, result);
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

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int size, int arr[]){
    printf("Sorted array is: ");
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
    }
}

int recursiveBinarySearch(int arr[], int key, int low, int high){
    if(low > high)
        return -1;
    
    int mid = (low + high) / 2; 

    if(arr[mid] == key)
        return mid;

    if(arr[mid] > key)
        return recursiveBinarySearch(arr, key, low, mid - 1); //search left

    return recursiveBinarySearch(arr, key, mid + 1, high); //search right
}