#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

typedef struct
{
    char **filenames; // 파일명 배열
    int count;        // 파일 개수
} FileList;

typedef struct {
    char **paths;
    int count;
    int capacity;
} ResultList;

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

void free_file_list(FileList *list)
{
    for (int i = 0; i < list->count; i++)
    {
        free(list->filenames[i]);
    }
    free(list->filenames);
    free(list);
}

void init_result_list(ResultList *list) {
    list->paths = NULL;
    list->count = 0;
    list->capacity = 0;
}

void add_result(ResultList *list, const char *path) {
    if (list->count >= list->capacity) {
        list->capacity = list->capacity == 0 ? 16 : list->capacity * 2;
        list->paths = realloc(list->paths, list->capacity * sizeof(char *));
    }
    list->paths[list->count++] = strdup(path);
}

void free_result_list(ResultList *list) {
    for (int i = 0; i < list->count; i++) {
        free(list->paths[i]);
    }
    free(list->paths);
}

void find(const char *path, const char *file_name, ResultList *results) {
    FileList *file_list = ls_cmd(path);
    if (file_list == NULL) {
        return;
    }
    if (file_list->count == 0) {
        free_file_list(file_list);
        return;
    }

    struct stat file_stat;
    for (int i = 0; i < file_list->count; i++) {
        const char *file = (const char *)file_list->filenames[i];
        if (!strcmp(file, ".") || !strcmp(file, "..")) {
            continue;
        }

        char *file_buf = concat_path(path, file);

        if (lstat(file_buf, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                find(file_buf, file_name, results);
            } else if (!strcmp(file, file_name)) {
                add_result(results, file_buf);
            }
        } else {
            printf("%s - stat failed: %s\n", file_buf, strerror(errno));
        }

        free(file_buf);
    }
    
    free_file_list(file_list);
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Usage: ./find [path] <file name>\n");
        return 0;
    } 
    const char * path = argc < 3 ? "./" : argv[1];
    const char * file_name = argc < 3 ?  argv[1] : argv[2];
    
    ResultList results;
    init_result_list(&results);
    
    find(path, file_name, &results);
    
    if (results.count == 0) {
        printf("No files found.\n");
    } else {
        printf("Found %d file(s):\n", results.count);
        for (int i = 0; i < results.count; i++) {
            printf("%s\n", results.paths[i]);
        }
    }
    
    free_result_list(&results);
    return 0;
}