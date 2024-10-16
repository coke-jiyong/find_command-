#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
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

    if ((dir = opendir(path)) == NULL)
    {
        printf("Directory open error\n");
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

// int main(int argc, char *argv[])
// {
//     const char *path = (argc > 1) ? argv[1] : ".";
//     FileList *files = ls_cmd(path);

//     if (files)
//     {
//         printf("Files in directory %s:\n", path);
//         for (int i = 0; i < files->count; i++)
//         {
//             printf("%s\n", files->filenames[i]);
//         }
//         printf("Total files: %d\n", files->count);

//         free_file_list(files);
//     }

//     return 0;
// }