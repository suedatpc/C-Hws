#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    struct Node* next;
}Node;

Node* first = NULL;

void addToLast(int x){
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

void deleteAll(int x){
    if(first -> num == x){
        Node* temp = first;
        first = first -> next;
        free(temp);
    }

    Node* current = first;
    while(current != NULL && current -> next != NULL){
        if(current -> next -> num == x){
            Node* temp = current -> next;
            current -> next = current -> next -> next;
            free(temp);
        }else{
            current = current -> next;
        }
    }
}

void deleteAfterPos(int pos){
    int i = 1;
    Node* current = first;
    
    while(current != NULL && i < pos){
        current = current -> next;
        i++;
    }

    if(current == NULL || current -> next == NULL){
        return;
    }

    Node* temp = current -> next;
    Node* next;
    while(temp != NULL){
        next = temp -> next;
        free(temp);
        temp = next;
    }

    current -> next = NULL;
}

int main(){
    while(1){
        int n;
        printf("Enter a number to add it(-1 to quit): ");
        scanf("%d", &n);
        if(n == -1)
            break;
        addToLast(n);
    }
    print();

    printf("Enter a number to remove it from the list: ");
    int num;
    scanf("%d", &num);
    deleteAll(num);
    print();

    int pos;
    printf("Enter the position after which to delete nodes: ");
    scanf("%d", &pos);
    deleteAfterPos(pos);
    print();
}