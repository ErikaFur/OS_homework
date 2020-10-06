#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <unistd.h>
#include "string.h"
int main(){
    int time = 10;
    int *arr;
    for (int i = 0; i < time; ++i) {
        arr = malloc(10*1024*1024);
        memset(arr, 0 , 10*1024*1024);
        sleep(1);
    }
    return 0;
}

/*
 *   PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
   2654 senfur    20   0 7444348 408912 129780 S 518,0   2,5 221:40.32 zoom
    814 root      20   0 1616172 230052 134820 S   6,0   1,4   9:05.86 Xorg
    910 senfur     9 -11 1408588  19720  15544 S   6,0   0,1   3:27.64 pulseaudio
   1047 senfur    20   0 1992948 193176 143856 S   3,0   1,2  28:29.73 kwin_x11
   1055 senfur    20   0 4223888 327120 160112 S   1,0   2,0   1:44.93 plasmashell
   1331 senfur    20   0 1587528  90820  72904 S   1,0   0,6   0:12.53 konsole
   1418 senfur    20   0 3030776 396464 172936 S   1,0   2,4   2:11.09 MainThread
   1862 senfur    20   0 2870636 296236 139392 S   1,0   1,8   0:36.81 Web Content
   2608 senfur    20   0 2621248 187744 131280 S   1,0   1,2   0:14.77 Web Content
   2786 root      20   0       0      0      0 I   1,0   0,0   0:03.58 kworker/2:0-events
  39180 root      20   0       0      0      0 I   1,0   0,0   0:00.06 kworker/0:1-events
  39191 senfur    20   0   94684  93288   1136 S   1,0   0,6   0:00.04 ex3
  *
 */

/*
 *    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
   2654 senfur    20   0 7483312 480840 130424 R 174,3   3,0 230:49.22 zoom
   1047 senfur    20   0 1992784 193476 143856 S  23,8   1,2  29:11.94 kwin_x11
    910 senfur     9 -11 1408588  19720  15544 S   7,9   0,1   3:36.00 pulseaudio
    814 root      20   0 1624656 238536 135204 S   4,0   1,5   9:24.42 Xorg
   1418 senfur    20   0 3030776 397868 172936 S   2,0   2,4   2:13.39 MainThread
   1331 senfur    20   0 1588228  91404  73288 S   1,0   0,6   0:13.68 konsole
   1497 senfur    20   0 3571904 319452 130988 S   1,0   2,0   1:29.39 telegram-deskto
   2013 senfur    20   0 2555284 203008 112492 S   1,0   1,2   1:06.46 file:// Content
   3885 senfur    20   0 2533272 205800 101828 S   1,0   1,3   0:09.25 Web Content
   6316 root      20   0       0      0      0 I   1,0   0,0   0:00.59 kworker/5:2-events
  39257 senfur    20   0   53708  52384   1148 S   1,0   0,3   0:00.02 ex3
 */

/*
 * according to output, size if %MEM increase as time of execution is increasing.
 *
 *
 * also I mentioned that zoom use 500% of my CPU. What a pain...
 */