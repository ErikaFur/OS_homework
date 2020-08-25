#include <stdio.h>

int main(){
    int z;
    float x;
    double c;
    z = __INT_MAX__;
    x = __FLT_MAX__;
    c = __DBL_MAX__;
    printf("size of int = %ld\nsize of float = %ld\nsize of double = %ld\nz = %d\nx = %f\nc = %lf",sizeof(z),sizeof(x),sizeof(c),z,x,c);

}