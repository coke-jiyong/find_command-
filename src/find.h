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
} FileList;

FileList *ls_cmd(const char *path);
void free_file_list(FileList *list);
void print_path(const char *path, const char *file_name);
char *concat_path(const char *path, const char *file_name);
void find(const char *path, const char *file_name);