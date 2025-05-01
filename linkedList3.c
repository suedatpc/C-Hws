#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node* next;
}Node;

Node *first = NULL;
Node *reversed_head = NULL;

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

void insertToReversed(int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode -> num = x;
    newNode -> next = reversed_head;
    reversed_head = newNode;
}

void print(){
    Node* temp = first;
    while(temp != NULL){
        printf("%d -> ", temp -> num);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void recursivePrint(Node* node){
    if(node == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", node -> num);
    recursivePrint(node -> next);
}

void reverseRecursivePrint(Node* node){
    if(node == NULL){
        return;
    }
    reverseRecursivePrint(node -> next);
    printf("%d -> ", node -> num);
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
    recursivePrint(first);
    reverseRecursivePrint(first);
    printf("NULL\n");
    
    Node* temp = first;
    while(temp != NULL){
        insertToReversed(temp -> num);
        temp = temp -> next;
    }
    printf("Reversed list (using 2nd list): \n");
    recursivePrint(reversed_head);
    

    return 0;
}