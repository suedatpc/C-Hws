#include <stdio.h>

struct ComplexNum
{
    int imaginary;
    int real;
};

void ComplexAdd(struct ComplexNum complex[]){
    int I, R;
    I = complex[0].imaginary + complex[1].imaginary;
    R = complex[0].real + complex[1].real;
    printf("Result: %d + %di", R, I);
}


int main(){
    struct ComplexNum complex[2];

    printf("Please enter your first complex number's real and imaginary value: ");
    scanf("%d %d", &complex[0].real, &complex[0].imaginary);
    printf("Please enter your second complex number's real and imaginary value: ");
    scanf("%d %d", &complex[1].real, &complex[1].imaginary);

    ComplexAdd(complex);

    return 0;
}
