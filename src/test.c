#include "find.h"


int main(void) {

    //concat_path() test
    // char buf[4096];
    // concat_path("./", "myfile",buf);
    // printf("%s\n", buf);

    //ls_cmd() test
    // FileList * file = ls_cmd("./test_dir");
    // assert(file != NULL);
    // print_list(file);
    
    // free_file_list(file);
    
    //find() test
    // PathList path_list = {
    //     .capacity=0,
    //     .count=0,
    //     .pathlists=NULL
    // };

    // find("./" , "memcheck.txt" , &path_list);

    // if (path_list.count == 0) {
    //     printf("This file not found.\n");
    //     return 0;
    // }

    // printf("%d file found.\n", path_list.count);
    // for(int i = 0 ; i < path_list.count ; i ++) {
    //     printf("%s\n", path_list.pathlists[i]);
    // }
    // free_path_list(&path_list);

    //list_test
    FileList* dir_head = NULL;
    append_file_name(&dir_head , "hello");
    append_file_name(&dir_head , "World");
    append_file_name(&dir_head , "park");
    append_file_name(&dir_head , "love C");
    

    print_list(dir_head);
    free_file_list(dir_head);

    return 0;
}