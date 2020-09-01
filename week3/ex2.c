#include <stdio.h>

void bubble_sort(int size, int *arr){
    int temp = 0;
    for(int i = 0; i < size -1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&array[i]);
    }
    printf("Unsorted array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ",array[i]);
    }
    printf("\nSorted array:\n");
    bubble_sort(n, array);
    for (int i = 0; i < n; ++i) {
        printf("%d ", array[i]);
    }
    return 0;
}