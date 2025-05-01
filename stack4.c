#include <stdio.h>
#include <string.h>
#define MAX 25
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
    char word[MAX];
    char reversedWord[MAX];
    printf("Enter a word: ");
    scanf("%s", &word);

    for(int i = 0; i < strlen(word); i++){
        Push(word[i]);
    }

    for(int i = 0; i < strlen(word); i++){
        reversedWord[i] = Pop();
    }

    if(strcmp(word, reversedWord) == 0)
        printf("The word is a polindrome.");
    else 
        printf("The word is not a polindrome.");
}