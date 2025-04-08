#include <stdio.h>

struct rectangle{
    float length;
    float breadth;
};

float calculateArea(struct rectangle r){
    return r.length * r.breadth;
}

int main(){
    struct rectangle r;
    printf("Enter the length of the rectangle: ");
    scanf("%f", &r.length);
    printf("Enter the breadth of the rectangle: ");
    scanf("%f", &r.breadth);

    float result = calculateArea(r);
    printf("The area of the rectangle is: %.2f\n", result);

    return 0;
}