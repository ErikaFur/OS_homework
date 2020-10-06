#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void* new_realloc(void* ptr, size_t old_size, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    void* array = malloc(size);
    if (ptr == NULL) {
        return array;
    }
    if (old_size > size) {
        memcpy(array, ptr, size);
    }
    else {
        memcpy(array, ptr, old_size);
    }
    free(ptr);
    return array;
}


int main() {
    int n1 = 5;
    int n2 = 9;
    int* arr;
    arr = new_realloc(NULL, n1*sizeof(*arr) , n2 * sizeof(*arr)); //pass without ptr
    for (int i = 0; i < n1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = malloc(n1 * sizeof(int));
    for (int i = 0; i < n1; ++i) {
        scanf_s("%d", &arr[i]);
    }
    for (int i = 0; i < n1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    arr = new_realloc(arr, n1 * sizeof(*arr), n2 * sizeof(*arr));
    arr[6] = 14;
    for (int i = 0; i < n2; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
