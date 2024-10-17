#include "find.h"
#include <assert.h>



int main(int argc, char* argv[])
{   
    const char * path = "/home/ubuntu/mytmp/";
    const char * file_name = "myfile";
    int need_slash = path[strlen(path) -1] != '/';
    size_t total_size = strlen(path) + strlen(file_name) + 1 + need_slash; // +1은 '\0'
    assert(total_size >= strlen(path) + strlen(file_name) + 1);

    char * buf = (char*)malloc(total_size);
    if (buf == NULL) {
        return 0;
    }
    strcpy(buf , path);
    if (need_slash) {
        strcat(buf ,  "/");
    }
    strcat(buf,file_name);
    
    printf("%s\n",buf);

    free(buf);






    struct stat file_stat;
    if (lstat(file_buf, &file_stat) == 0) {
        if (S_ISDIR(file_stat.st_mode)) {
            assert(file_buf != NULL);
            find(file_buf, file_name);
        } else if (S_ISLNK(file_stat.st_mode)) {
            // 심볼릭 링크 처리
            char link_target[PATH_MAX];
            ssize_t len = readlink(file_buf, link_target, sizeof(link_target)-1);
            if (len != -1) {
                link_target[len] = '\0';
                printf("%s is a symbolic link to %s\n", file_buf, link_target);
                // 필요하다면 링크 대상을 따라갈 수 있습니다
                // find(link_target, file_name);
            } else {
                printf("%s - readlink failed: %s\n", file_buf, strerror(errno));
            }
        }
    } else {
        printf("%s - lstat failed: %s\n", file_buf, strerror(errno));
    }

}