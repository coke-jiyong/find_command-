#include "find.h"


char file_name[NAME_MAX];

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
    find((void*)path);
    
    return 0;
}