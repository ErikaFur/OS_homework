#include <stdio.h>
#include <unistd.h>
int main(){
    for (int i = 0; i < 3; ++i) {
        fork();
    }
    sleep(5);
    return 0;
}
//We got this result. We have 8 'ex2' processes
//after 1-st fork we have a child process, which loops for 2 times (as a parent) after that this process repeats till i != 3
//in result we have 2 * 2 * 2 = 8
//-ex2_bash-+-ex2-+-ex2-+-ex2---ex2
//         |     |     `-ex2
//         |     |-ex2---ex2
//         |     `-ex2