#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sys/mman.h"

int main() {
    int z = open("/home/senfur/Innopolis/os_homework/week11/ex1.txt", O_RDWR);
    int z1 = open("/home/senfur/Innopolis/os_homework/week11/ex1.memcpy.txt", O_RDWR);
    FILE *fp;
    struct stat* buff = malloc (sizeof(struct stat));
    struct stat* buff1 = malloc (sizeof(struct stat));
    stat("/home/senfur/Innopolis/os_homework/week11/ex1.txt", buff);
    stat("/home/senfur/Innopolis/os_homework/week11/ex1.memcpy.txt", buff1);
    size_t x = buff->st_size;
    size_t x1 = buff1->st_size;
    void* map = mmap(NULL, x, PROT_READ, MAP_SHARED, z, 0);
    void* map1 = mmap(NULL, x1, PROT_WRITE, MAP_SHARED, z1, 0);
    truncate("/home/senfur/Innopolis/os_homework/week11/ex1.memcpy.txt", sizeof(char) * x);
    strcpy(map1, map);
    return 0;
}