#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

int isEmpty(){
    if(top == -1)
            return 1;
    return 0;
}

int isFull(){
    if(top == MAX - 1)
        return 1;
    return 0;
}

void Push(char x){
    if(isFull())
        return;
    top++;
    stack[top] = x;
}

char Pop(){
    if(isEmpty())
        return -1;
    char x = stack[top];
    top--;
    return x;
}

void print(){
    if(isEmpty())
        return;
    for(int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}


int main(){
    char expression[MAX];
    printf("Enter an expression: ");
    fgets(expression, MAX, stdin);

    for(int i = 0; i < strlen(expression); i++){
        if(expression[i] == '('){
            Push('(');
        }else if(expression[i] == ')'){
            Pop();
        }
    }
    
    if(isEmpty())
        printf("No parantheses error found.");
    else
        printf("Parantheses error!");

    return 0;
}