#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

void createArr(int size, int arr[]);
void printArr(int size, int arr[]);
void swap(int a, int b, int arr[]);
void bubbleSort(int size, int arr[]);
void selectionSort(int size, int arr[]);


int main(){
    srand(time(0));
    int size;
    char sort;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int numbers[size];

    createArr(size, numbers);
    printArr(size, numbers);

    printf("Enter 'B' for Bubble sort, 'S' for selection sort: ");
    scanf(" %c", &sort);
    sort = toupper(sort);
    
    if(sort == 'B'){
        bubbleSort(size, numbers);
    }else if(sort == 'S'){
        selectionSort(size, numbers);
    }else{
        printf("Invalid choice. Please enter 'B' or 'S'.\n");
    }

    return 0;
}

void createArr(int size, int arr[]){
    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100;
    }
}

void printArr(int size, int arr[]){
    printf("The array is: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    } 
    printf("\n");  
}

void swap(int a, int b, int arr[]){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void bubbleSort(int size, int arr[]){
    int iteration = 0;
    for(int step = 0; step < size; step++){
        for(int i = 0; i < size - 1; i++){
            if(arr[i] > arr[i + 1]){
                swap(i, i + 1, arr);
                iteration++;
                printf("%d. iteration -> ", iteration);
                printArr(size, arr);
            }
        }
    }
}

void selectionSort(int size, int arr[]){
    int iteration = 0;
    for(int i = 0; i < size - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(i, minIndex, arr);
        iteration++;
        printf("%d. iteration -> ", iteration);
        printArr(size, arr);
    }
}