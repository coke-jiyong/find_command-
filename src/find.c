#include "find.h"

FileList *ls_cmd(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    FileList *result = (FileList *)malloc(sizeof(FileList));
    result->count = 0;
    result->capacity = 0;
    result->filenames = NULL;

    if ((dir = opendir(path)) == NULL) // error 실행파일 일 경우 if문 걸림
    {
        // printf("%s: %s\n",path,strerror(errno));
        free(result);
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL)
    {   
        if(result->capacity <= result->count) {
            result->capacity = result->capacity == 0 ? 10 : result->capacity * 2;
            result->filenames = realloc(result->filenames , result->capacity * sizeof(char*));
        }
        result->filenames[result->count++] = strdup(entry->d_name);
        
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

void concat_path(const char *path, const char *file_name, char * buf)
{
    int need_slash = path[strlen(path) - 1] != '/';
    memset(buf , 0 , PATH_MAX);
    strcpy(buf, path);
    if (need_slash)
    {
        strcat(buf, "/");
    }
    strcat(buf, file_name);
}

void find(const char *path, const char *file_name, PathList *path_list)
{
    FileList * file_list = ls_cmd(path);
    assert(file_list != NULL);

    struct stat file_stat;
    char current_file_path[PATH_MAX];
    for(int i = 0 ; i < file_list->count ; i ++) {
        const char *current_file_name = (const char*)file_list->filenames[i];
        if (!strcmp(current_file_name , ".") || !strcmp(current_file_name , "..")) {
            continue;
        }

        concat_path(path, current_file_name, current_file_path);
        if (lstat(current_file_path, &file_stat) == 0) {
            if (S_ISDIR(file_stat.st_mode)) {
                find(current_file_path, file_name , path_list);
            } else if(!strcmp(current_file_name , file_name)) {
                add_path_list(path_list , current_file_path);
            }
        } else {
            printf("%s - stat failed: %s\n", current_file_path, strerror(errno));
        }
    }
    free_file_list(file_list);
}

void add_path_list(PathList *path_list , char * file_path) {
    if (path_list->capacity <= path_list->count) {
        path_list->capacity = path_list->capacity == 0 ? 10 : path_list->capacity * 2;
        path_list->pathlists = realloc(path_list->pathlists , path_list->capacity * sizeof(char*));
    }
    path_list->pathlists[path_list->count++] = strdup(file_path);
}

void free_path_list(PathList *path_list) {
    for (int i = 0 ; i < path_list->count ; i ++) {
        free(path_list->pathlists[i]);
    }
    free(path_list->pathlists);
}