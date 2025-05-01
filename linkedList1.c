#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node* next;
}Node;

Node *first = NULL;

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

void print(){
    Node* temp = first;
    while(temp != NULL){
        printf("%d -> ", temp -> num);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int nodeCount(){
    int count = 0;
    Node* temp = first;

    while(temp != NULL){
        temp = temp -> next;
        count++;
    }
    return count;
}

int findSum(){
    Node* temp = first;
    int sum = 0;

    while(temp != NULL){
        sum += temp -> num;
        temp = temp -> next;
    }
    return sum;
}

void findPos(int n){
    int count = 1;
    Node* temp = first;
    while(temp != NULL){
        if(temp -> num == n){
            printf("The number is at position %d\n", count);
            return;
        }
        temp = temp -> next;
        count++;    
    }
    printf("The number %d is not found in the list.\n", n);
}

void findNum(int pos){
    int count = 1;
    Node* temp = first;
    while(temp != NULL){
        if(count == pos){
            printf("The number at position %d is: %d", pos, temp -> num);
        }
        temp = temp -> next;
        count++;
    }
}

int main(){
    while(1){
        int n;
        printf("Enter a number to add it(-1 to quit): ");
        scanf("%d", &n);
        if(n == -1)
            break;
        addLast(n);
    }

    print();
    printf("The number of nodes: %d\n", nodeCount());
    printf("The sum of the numbers: %d\n", findSum());
    printf("The average is: %d\n", findSum() / nodeCount());
    int n;
    printf("Enter a number to find it's position: ");
    scanf("%d", &n);
    findPos(n);
    int pos;
    printf("Enter a position to get a number: ");
    scanf("%d", &pos);
    findNum(pos);
    
    return 0;
}