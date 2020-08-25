#include <stdio.h>
#include <string.h>
int main(){
    int i = 100000;
    char str[i];
    scanf("%s",str);
    for (int i = 0; i < strlen(str); ++i) {
        printf("%c", str[strlen(str)-1-i]);
    }
}