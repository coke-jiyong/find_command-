#include "ls.h"


void find(const char * path , const char * file_name) {
    FileList * file_list = (path);

    if (file_list->count == 0 || file_list == NULL) {
        free_file_list(file_list);
        return ;
    }

    //찾는 파일이 있다면 경로 + 파일명 출력 후 리턴
    struct stat file_stat;
    for(int i = 0 ; i < file_list->count ; i ++) {
        if (strcmp((const char *)file_list->filenames[i] , file_name) == 0) {
            printf("%s%s%s\n", path , "/" , file_list->filenames[i]);
            return;
        }
        
        if(stat((const char *)file_list->filenames[i], &file_stat) == 0) {
            if(S_ISDIR(file_stat.st_mode)) {
                printf("%s\n", file_list->filenames[i]);
            }
        }
    }

    //없다면 파일 종류중 디렉토리 확인 후 현재경로 + 디렉토리명 을 경로로 find 다시호출
    


    free_file_list(file_list);
}
int main(int argc, char* argv[])
{   
    if (argc == 1) {
        printf("Usage: ./find [path] <file name>\n");
        return 0;
    } 
    const char * path = argc < 3 ? "./" : argv[1];
    const char * file_name = argc < 3 ?  argv[1] : argv[2];
    
    
    
    return 0;

}