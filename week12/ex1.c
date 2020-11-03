
#include <stdio.h>


int main() {
    int byte_count = 20;
    char rand[20];
    FILE *file = fopen("/dev/random", "r");
    fread(&rand, 1, byte_count, file);
    file = fopen("/home/senfur/Innopolis/os_homework/week12/ex1.txt", "w");
    fprintf(file, "%s", rand);
    fclose(file);
    return 0;
}