#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    printf("input N\n");
    scanf("%d", &N);
    int *array = calloc(N,sizeof(int));
    for (int i = 0; i < N; ++i) {
        *(array + i) = i;
    }
    for (int i = 0; i < N; ++i) {
        printf("%d ",*(array + i));
    }
    free(array);
}