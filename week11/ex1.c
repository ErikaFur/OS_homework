#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <values.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sys/mman.h"

int main() {
    int z = open("/home/senfur/Innopolis/os_homework/week11/ex1.txt", O_RDWR);
    FILE *fp;
    char *str = "This is a nice day";
    struct stat* buff = malloc (sizeof(struct stat));
    stat("/home/senfur/Innopolis/os_homework/week11/ex1.txt", buff);
    size_t x = buff->st_size;
    void* map = mmap(NULL,x, PROT_READ | PROT_WRITE, MAP_SHARED, z, 0);
    truncate("/home/senfur/Innopolis/os_homework/week11/ex1.txt", sizeof(char) * 19);
    strcpy(map, str);
    return 0;
}