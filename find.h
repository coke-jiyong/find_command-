#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

// 결과를 저장할 구조체 정의

typedef struct
{
    char **filenames; // 파일명 배열
    int count;        // 파일 개수
} FileList;

FileList *ls_cmd(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    FileList *result = (FileList *)malloc(sizeof(FileList));
    result->count = 0;
    result->filenames = NULL;

    if ((dir = opendir(path)) == NULL) // error 실행파일 일 경우 if문 걸림
    {
        // printf("%s: %s\n",path,strerror(errno));
        free(result);
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL)
    {
        result->count++;
    }

    result->filenames = (char **)malloc(sizeof(char *) * result->count);

    // 디렉토리 스트림 재설정 -> 위의 while문에서 디렉토리 스트림은 끝까지 가있기때문. rewinddir 하지 않으면 아무 파일도 읽지 못함.
    rewinddir(dir);

    int i = 0;
    while ((entry = readdir(dir)) != NULL)
    {
        result->filenames[i++] = strdup(entry->d_name);
    }

    if (closedir(dir) == -1)
    {
        printf("close directory failed.\n");
    }
    return result;
}

void free_file_list(FileList *list)
{
    for (int i = 0; i < list->count; i++)
    {
        free(list->filenames[i]);
    }
    free(list->filenames);
    free(list);
}

void print_path(const char *path, const char *file_name)
{
    if (!strcmp(path, "./"))
    {
        printf("%s%s\n", path, file_name);
    }
    else
    {
        if (path[strlen(path) - 1] == '/')
        {
            printf("%s%s\n", path, file_name);
        }
        else
        {
            printf("%s%s%s\n", path, "/", file_name);
        }
    }
}

char *concat_path(const char *path, const char *file_name)
{

    int need_slash = path[strlen(path) - 1] != '/';
    size_t total_size = strlen(path) + strlen(file_name) + 1 + need_slash; // +1은 '\0'
    assert(total_size >= strlen(path) + strlen(file_name) + 1);

    char *buf = (char *)malloc(total_size);
    if (buf == NULL)
    {
        return NULL;
    }
    strcpy(buf, path);
    if (need_slash)
    {
        strcat(buf, "/");
    }
    strcat(buf, file_name);
    return buf; // free 필수
}

void find(const char *path, const char *file_name)
{
    FileList *file_list = ls_cmd(path);
    if (file_list == NULL)
    {
        return;
    }
    if (file_list->count == 0)
    {
        free_file_list(file_list);
        return;
    }

    // 찾는 파일이 있다면 경로 + 파일명 출력 후 리턴
    struct stat file_stat;
    for (int i = 0; i < file_list->count; i++)
    {
        const char *file = (const char *)file_list->filenames[i];
        if (!strcmp(file, ".") || !strcmp(file, ".."))
        {
            continue;
        }

        if (!strcmp(file, file_name))
        {
            print_path(path, file_name);
            free_file_list(file_list);
            return;
        }

        char *file_buf = concat_path(path, file);

        if (stat(file_buf, &file_stat) == 0)
        {
            if (S_ISDIR(file_stat.st_mode))
            {
                assert(file_buf != NULL);
                find(file_buf, file_name);
            }
        }
        else
        {
            printf("%s - stat failed: %s\n", file_buf, strerror(errno));
        }

        free(file_buf);
    }

    free_file_list(file_list);
}