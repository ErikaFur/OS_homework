#include <stdio.h>
#include <unistd.h>
int main(){
    int k = 23;
    int parent = getpid();
    int n = getpid();
    if (n == parent){
        printf("Hello from parent [%d - %d]\n", n, k);
    }else{
        printf("Hello from child [%d - %d]\n", n, k);
    }
    fork();
    n = getpid();
    if (n != parent){
        printf("Hello from child [%d - %d]\n", n, k);
    }
    return 0;
}

//Hello from parent [8109 - 23]
//Hello from child [8110 - 23]
//Hello from parent [8111 - 23]
//Hello from child [8112 - 23]
//Hello from parent [8113 - 23]
//Hello from child [8114 - 23]
//Hello from parent [8115 - 23]
//Hello from child [8116 - 23]
//Hello from parent [8117 - 23]
//Hello from child [8118 - 23]
//Hello from parent [8119 - 23]
//Hello from child [8120 - 23]
//Hello from parent [8121 - 23]
//Hello from child [8122 - 23]
//Hello from parent [8123 - 23]
//Hello from child [8124 - 23]
//Hello from parent [8125 - 23]
//Hello from child [8126 - 23]
//Hello from parent [8127 - 23]
//Hello from child [8128 - 23]

