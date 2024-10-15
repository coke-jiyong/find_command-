#include<stdio.h>
#include<stdlib.h>

// 디렉터리 관련 DIR, struct dirent, opendir(), readdir(), closedir() 등이 정의된 헤더 포함
#include<dirent.h>

// Unix 에 쓰이는 표준 심볼들과 상수, 함수들이 정의된 헤더 포함
#include<unistd.h>

int main(int argc, char* argv[])
{
    char * cwd = (char *)malloc(sizeof(char) * 1024);       
    DIR * dir = NULL;
    struct dirent * entry = NULL;

    if(argc==1) {
        getcwd(cwd, 1024);
        if((dir = opendir(cwd)) == NULL) {
            printf("current directory open error\n");
            free(cwd);
            exit(1);
        }
    } else {
        // main 함수에 추가 인자가 전달된 경우 argv[1] 문자열로 디렉토리 스트림 열어
        // 디렉토리 포인터 변수에 담기
        if((dir = opendir(argv[1])) == NULL)
        {
            printf("directory open error\n");
            free(cwd);
            exit(1);
        }
    }

    // readdir()함수는 디렉토리 포인터를 통해서 디렉토리 정보를 하나씩 차례대로 읽음
    // 디렉토리 스트림의 끝에 도달하거나 에러가 발생하면 NULL을 리턴
    // 정상적으로 읽은 경우 struct dirent 구조체 포인터를 반환하는데 이 값을 entry에 저장하고
    // 파일명이 저장된 구조체 멤버인 char 배열 d_name을 문자열로 출력
    while((entry = readdir(dir)) != NULL)
    {
        printf("%ld %s -> len:%d\n", entry->d_ino ,entry->d_name,entry->d_reclen);
        //printf("d_reclen: %d , d_type: %c ,d_off: %ld\n", entry->d_reclen, entry->d_type ,entry->d_off);
    }

    printf("\n");
    free(cwd);
    return 0;

}