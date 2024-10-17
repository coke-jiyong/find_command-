#include "find.h"

void print_path(PathList *list) {
    if (list->count == 0) {
        printf("This file not found.\n");
        return;
    }

    printf("%d file found.\n", list->count);
    for(int i = 0 ; i < list->count ; i ++) {
        printf("%s\n", list->pathlists[i]);
    }
}
int main(int argc, char* argv[])
{
    if (argc == 1) {
        printf("Usage: ./find [path] <file name>\n");
        return 0;
    } 
    const char * path = argc < 3 ? "./" : argv[1];
    const char * file_name = argc < 3 ?  argv[1] : argv[2];

    PathList path_list = {
        .capacity=0,
        .count=0,
        .pathlists=NULL
    };

    find(path , file_name , &path_list);

    print_path(&path_list);

    free_path_list(&path_list);
    return 0;
}