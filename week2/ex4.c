#include <stdio.h>

void swap(double *num1, double *num2){
    double temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main(){
    double a = 0,b = 0;
    printf("Input number a\n");
    scanf("%lf",&a);
    printf("Input number b\n");
    scanf("%lf",&b);
    printf("before swap: a = %lf, b = %lf\n",a,b);
    swap(&a,&b);
    printf("after swap: a = %lf, b = %lf",a,b);
}

