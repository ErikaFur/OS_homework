#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main(){
    char arg[10000];
    while(strcmp(arg,"exit")) {
        gets(arg);
        system(arg);
    }
    return 0;
}