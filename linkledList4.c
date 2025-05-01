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

int findAverage(){
    int sum = 0, i = 0;
    Node* temp = first;
    while(temp != NULL){
        sum += temp -> num;
        temp = temp -> next;
        i++;
    }
    return sum / i;
}

void delete(int x){
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

void deleteList(){
    Node* temp;
    while(first != NULL){
        temp = first;
        first = first -> next;
        free(temp);
    }
    printf("The list is deleted.\n");
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
    int avg = findAverage(); 

    Node* temp = first;
    while(temp != NULL){
        Node* next = temp -> next;
        if(temp -> num < avg)
            delete(temp -> num);
        temp = next;
    }
    
    print();
    deleteList();
    print();


    return 0;
}