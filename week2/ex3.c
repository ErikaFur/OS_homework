#include <stdio.h>

int main(int argc, char *argv[]){
    int n;
    sscanf(argv[1],"%d", &n);
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n-1; ++k) {
            if(j<n-1-k){
                printf(" ");
            } else{
                printf("*");
            }
        }
        printf("*");
        for (int k = 0; k < n-1; ++k) {
            if(j<k+1){
                printf(" ");
            } else{
                printf("*");
            }
        }
        printf("\n");
    }
}
