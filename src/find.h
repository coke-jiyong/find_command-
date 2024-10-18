#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <assert.h>
#define PATH_MAX 4096
#define FILE_NAME_MAX 256


typedef struct node
{
    char filename[FILE_NAME_MAX];
    struct node * next; 
} FileList;


extern int found_count;

FileList *ls_cmd(const char *path);
FileList *make_new_node();
void append_file_name(FileList **dir_head, char *file_name);
void concat_path(const char *path, const char *file_name, char *buf);
void find(const char *path, const char *file_name);
void free_file_list(FileList *head);

void print_list(FileList *list); //for test