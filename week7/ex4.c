#include <stdio.h>
#include <malloc.h>
#include <memory.h>

void *new_realloc(void* ptr,size_t old_size,size_t size){
    if (size == 0){
        free(ptr);
        return NULL;
    }
    void* array =malloc(size);
    if (ptr == NULL){
        return array;
    }
    if (old_size > size){
        memcpy(array,ptr,size);
    }else{
        memcpy(array,ptr,old_size);
    }
    free(ptr);
    return array;
}


int main(){
    int n1 = 5;
    int n2 = 9;
    int *arr = new_realloc(NULL,n1,n2); //pass without ptr
    for (int i = 0; i < n1; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    free(arr);
    arr = malloc(n1*sizeof(int));
    for (int i = 0; i < n1; ++i) {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i < n1; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    arr = new_realloc(arr, n1, n2);
    for (int i = 0; i < n2; ++i) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}