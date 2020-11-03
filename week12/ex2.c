#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "sys/mman.h"

int main(int argc, char *argv[]) {
    char input[20000];
    char buff[1];
    int counter = 0;
    int file;
    int add = 0;
    while (read(STDIN_FILENO, buff, 1) > 0 || counter == 20000){
        input[counter] = buff[0];
        counter++;
    }
    input[19999] = '\0';
    //fclose(file);
    write(STDOUT_FILENO, &input, counter);
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0){
            add = 1;
            continue;
        }
        if (add){
            file = open(argv[i], O_WRONLY | O_APPEND);
            write(file, &input, counter);
            close(file);
        }
        else {
            file = open(argv[i], O_WRONLY);
            write(file, &input, counter);
            close(file);
        }
    }
    return 0;
}