#include <stdio.h>
#define MAX 20
int queue[MAX];
int front = -1, rear = -1;

int isFull(){
    if(rear == MAX - 1)
        return 1;
    return 0;
}

int isEmpty(){
    if(front == -1 && rear == -1)
        return 1;
    return 0;
}

void Enqueue(int x){
    if(isFull())
        return;
    if(front == -1)
        front++;
    rear++;
    queue[rear] = x;
}

void print(){
    if(isEmpty())
        return;
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
}

int main(){
    int sum = 0;
    while(1){
        int number;
        printf("Enter a number to enqueue(-1 to quit): ");
        scanf("%d", &number);

        if(number == -1)
            break;
        
        Enqueue(number);
        sum += number;
    }

    print();
    printf("\nThe largest number in the queue: ");

    int largest = queue[0];
    for(int i = front; i <= rear; i++){
        if(queue[i] > largest){
            largest = queue[i];
        }
    }
    printf("%d", largest);

    return 0;
}