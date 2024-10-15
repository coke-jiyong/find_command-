#include "ls.h"

int main(int argc, char* argv[])
{
    
    const char * path = argc == 1 ? "./" : argv[1];
    FileList * list = ls_cmd(path);

    for(int i = 0 ; i < list->count ; i ++) {
        printf("%s\n",list->filenames[i]);
    }   
    return 0;
}