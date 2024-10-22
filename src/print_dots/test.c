#include <stdio.h>
#include <string.h>

int main(void) {
    char message[] = "Searching for files ";
    int dot_count = 0;
    
    while (1) {
        char dots[6] = {0};


        if(dot_count < 5) {
            for(int i = 0 ; i < dot_count ; i ++) {
                dots[i] = '.';
            }
            dots[dot_count + 1] = '\0';
            dot_count ++;
        } else {
            dot_count = 0;
            memset(dots, 0 , sizeof(dots));
        }
        printf("\r%s", message);
        printf("%s",dots);
        fflush(stdout);
        usleep(300000);
    }
    return 0;
}