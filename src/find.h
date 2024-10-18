#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>

typedef struct
{
    char **filenames;
    int count;
    int capacity;
} FileList;

typedef struct {
    char ** pathlists;
    int count;
    int capacity;
} PathList;

#define PATH_MAX 4096

FileList *ls_cmd(const char *path);
void free_file_list(FileList *list);
void concat_path(const char *path, const char *file_name, char *buf);
void find(const char *path, const char *file_name, PathList *path_list);
void add_path_list(PathList *path_list , char * file_path);
void free_path_list(PathList *path_list);