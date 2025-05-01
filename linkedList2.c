#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node{
    int num;
    struct Node* next;
}Node;

Node *first = NULL;


void bubbleSort(int arr[], int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void addLast(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> num = x;
    newNode -> next = NULL;
    
    if(first == NULL){
        first = newNode;
    }else{
        Node* temp = first;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
        temp -> next = newNode;
    }
}

void printList(){
    Node* temp = first;
    while(temp != NULL){
        printf("%d -> ", temp -> num);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void changeElement(int pos, int x){
    int step = 1;
    Node* temp = first;

    while(temp != NULL){
        if(step == pos){
            temp -> num = x;
            break;
        }
        temp = temp -> next;
        step++;
    }
    printList();
}

void replaceNumber(int x, int y){
    Node* temp = first;
    while(temp != NULL){
        if(temp -> num == x){
            temp -> num = y;
        }
        temp = temp -> next;
    }
    printList();
}

int main(){
    int numbers[MAX];
    int count = 0;

    while(1){
        int n;
        printf("Enter a number to add it(-1 to quit): ");
        scanf("%d", &n);
        if(n == -1)
            break;
        numbers[count] = n;
        count++;
        
    }

    bubbleSort(numbers, count);

    for(int i = 0; i < count; i++){
        addLast(numbers[i]);
    }

    printList();

    int pos, x;
    printf("Enter a position and a number to change the element: ");
    scanf("%d %d", &pos, &x);
    changeElement(pos, x);

    int oldNum, newNum;
    printf("Enter the number to be replaced and the new number: ");
    scanf("%d %d", &oldNum, &newNum);
    replaceNumber(oldNum, newNum);
}