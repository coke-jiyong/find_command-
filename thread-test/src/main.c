#include "find.h"
#include <stdbool.h>

char file_name[NAME_MAX];
threadpool thpool;
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("Usage: ./find [path] <file name>\n");
        return 0;
    }
    const char * path = argc < 3 ? "./" : argv[1];
    strcpy(file_name , argc < 3 ?  argv[1] : argv[2]);

    
    printf("Searching for %s ...\n", file_name);
    fflush(stdout);
    thpool = thpool_init(4);
    find((void*)strdup(path));
    
    thpool_wait(thpool);
    thpool_destroy(thpool);
    pthread_mutex_destroy(&print_mutex);

    //find((void*)path);
    return 0;
}