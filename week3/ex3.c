#include <stdio.h>
#include <stdbool.h>
struct node{
    int value;
    struct node *child;
    bool have_child;
};

struct licked_list{
    struct node vertex;
    int size;
};

void delete_node(struct licked_list *arr, int index){
    if (index == 0){
        arr->vertex = *arr->vertex.child;
    }else if (index == arr->size - 1){
        struct node *init_node = &arr->vertex;
        for (int i = 0; i < index-1; ++i) {
            init_node = init_node->child;
        }
        init_node->child = NULL;
        init_node->have_child = false;
    } else{
        struct node *init_node = &arr->vertex;
        for (int i = 0; i < index-1; ++i) {
            init_node = init_node->child;
        }
        init_node->child = init_node->child->child;
    }
    arr->size--;
}

void print_list(struct licked_list *arr){
    struct node init_node = arr->vertex;
    while (init_node.have_child == true){
        printf("%d ",init_node.value);
        init_node = *init_node.child;
    }
    printf("%d\n", init_node.value);
}

void insert_node(struct licked_list *arr, struct node *new_node, int index){
    if (index == arr->size){
        if (arr->size == 0) {
            arr->vertex = *new_node;
        } else {
            struct node *init_node = &arr->vertex;
            while (init_node->have_child == true) {
                init_node = init_node->child;
            }
            init_node->child = new_node;
            init_node->have_child = true;
        }
    } else if (index == 0){
        struct node child = arr->vertex;
        new_node->have_child = true;
        arr->vertex = *new_node;
        arr->vertex.child = &child;
    }else{
        struct node *init_node = &arr->vertex;
        for (int i = 0; i < index-1; ++i) {
            init_node = init_node->child;
        }
        new_node->have_child = true;
        new_node->child = init_node->child;
        init_node->child = new_node;
    }
    arr->size++;
}

void create_LL(struct licked_list *arr){
    arr->size = 0;
    arr->vertex.child = NULL;
    arr->vertex.have_child = false;
    arr->vertex.value = -1;
}

void create_node(struct node *vertex, int z){
    vertex->value = z;
    vertex->child = NULL;
    vertex->have_child = false;
}


int main(){
    struct licked_list ll;
    struct node z;
    create_node(&z,3);
    struct node x;
    create_node(&x,5);
    struct node c;
    create_node(&c,6);
    struct node v;
    create_node(&v,123);
    create_LL(&ll);
    insert_node(&ll, &z,0);
    insert_node(&ll, &x,1);
    insert_node(&ll, &c,2);
    insert_node(&ll, &v,3);
    print_list(&ll);
    delete_node(&ll,0);
    print_list(&ll);
    return 0;
}