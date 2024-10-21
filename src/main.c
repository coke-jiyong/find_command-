#include "find.h"
#include <pthread.h>
#include <stdbool.h>

char file_name[NAME_MAX];
threadpool thpool;

int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("Usage: ./find [path] <file name>\n");
        return 0;
    }
    thpool = thpool_init(8);
    const char * path = argc < 3 ? "./" : argv[1];
    strcpy(file_name , argc < 3 ?  argv[1] : argv[2]);
    
    printf("path: %s , file_name: %s\n", path , file_name);
    printf("Searching for %s ...\n", file_name);
    fflush(stdout);

    thpool_add_work(thpool , find , (void*)path);
    
    thpool_wait(thpool);
    
    thpool_destroy(thpool);

    return 0;
}