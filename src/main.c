#include "find.h"


int main(int argc, char* argv[])
{
    
    if (argc == 1) {
        printf("Usage: ./find [path] <file name>\n");
        return 0;
    } 
    const char * path = argc < 3 ? "./" : argv[1];
    const char * file_name = argc < 3 ?  argv[1] : argv[2];
    find(path , file_name);

    
}