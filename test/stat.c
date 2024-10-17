#include "find.h"

char * concat_path(const char * path , const char * file_name) {
    
    int need_slash = path[strlen(path) -1] != '/';
    size_t total_size = strlen(path) + strlen(file_name) + 1 + need_slash; // +1은 '\0'
    assert(total_size >= strlen(path) + strlen(file_name) + 1);

    char * buf = (char*)malloc(total_size);
    if (buf == NULL) {
        return NULL;
    }
    strcpy(buf , path);
    if (need_slash) {
        strcat(buf ,  "/");
    }
    strcat(buf,file_name);
    return buf; //free 필수

}

void find(const char * path , const char * file_name) {
    FileList * file_list = ls_cmd(path);
    if (file_list == NULL) {
        return ;
    }
    if (file_list->count == 0) {
        free_file_list(file_list);
        return ;
    }

    //찾는 파일이 있다면 경로 + 파일명 출력 후 리턴
    struct stat file_stat;
    for(int i = 0 ; i < file_list->count ; i ++) {
        const char * file = (const char *)file_list->filenames[i];
        if(!strcmp(file,".") || !strcmp(file,"..")) {
            continue;
        }
        
        if (!strcmp(file , file_name)) {
            print_path(path , file_name);
            free_file_list(file_list);
            return;
        }
        
        char * file_buf = concat_path(path , file);

        if(stat(file_buf, &file_stat) == 0) { 
            if(S_ISDIR(file_stat.st_mode)) {
                assert(file_buf != NULL);
                find(file_buf, file_name);
            }
        }
        else {
            printf("%s - stat failed: %s\n", file_buf ,strerror(errno));
        }

        free(file_buf);
    }
    
    free_file_list(file_list);
}
int main(void) {

    find("./", "hello.txt");
    

    return 0;
}