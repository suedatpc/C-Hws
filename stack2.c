#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
int stack[SIZE];
int top = -1;

int isEmpty(){
    if(top == -1)
            return 1;
    return 0;
}

int isFull(){
    if(top == SIZE - 1)
        return 1;
    return 0;
}

void Push(int x){
    if(isFull())
        return;
    top++;
    stack[top] = x;
}

void Pop(){
    if(isEmpty())
        return;
    top--;
}

void print(){
    if(isEmpty())
        return;
    for(int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
}

int main(){
    srand(time(0));
    int num;

    for(int i = 0; i < SIZE; i++){
        num = rand() % 100;
        Push(num);
    }

    print();

    printf("\nEnter the number of elements to pop:");
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        Pop();
    }

    print();

    return 0;
}
