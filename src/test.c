#include "find.h"


int main(void) {

    //concat_path() test
    // char buf[4096];
    // concat_path("./", "myfile",buf);
    // printf("%s\n", buf);

    //ls_cmd() test
    // FileList * result = ls_cmd("./");
    // for (int i = 0 ; i < result->count ;i ++) {
    //     printf("%s  ", result->filenames[i]);
    // }
    // printf("\n");
    
    //find() test
    PathList path_list = {
        .capacity=0,
        .count=0,
        .pathlists=NULL
    };

    find("./" , "memcheck.txt" , &path_list);

    if (path_list.count == 0) {
        printf("This file not found.\n");
        return 0;
    }

    printf("%d file found.\n", path_list.count);
    for(int i = 0 ; i < path_list.count ; i ++) {
        printf("%s\n", path_list.pathlists[i]);
    }
    free_path_list(&path_list);
    return 0;
}