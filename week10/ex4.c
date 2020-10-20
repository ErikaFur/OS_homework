#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <values.h>
#include <dirent.h>
#include <sys/stat.h>

int *address;
int *state;


int main() {
    struct stat *buff = malloc(sizeof(struct stat) * 10);
    char *path[255];
    strcpy(path, "/home/senfur/Innopolis/os_homework/week10");
    FILE *file;
    strcat(path, "/tmp");
    DIR *dirp = opendir(path);
    struct dirent *dp;
    if(dirp == NULL){
        return -1;
    }
    char *path1[255];
    while ((dp = readdir(dirp)) != NULL){
        strcpy(path1, path);
        strcat(path1,"/");
        strcat(path1, dp->d_name);
        stat(path1, buff);
        if(buff->st_nlink > 1){
            printf("file %s has inode %lu and number of links = %lu\n",dp->d_name , buff->st_ino, buff->st_nlink);
        }
    }
    return 0;
}