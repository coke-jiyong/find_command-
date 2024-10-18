#include "find.h"

int found_count = 0;

FileList *ls_cmd(const char *path)
{
    DIR *dir;
    struct dirent *entry;
    FileList* dir_head = NULL;
    
    if ((dir = opendir(path)) == NULL) // error 실행파일 일 경우 if문 걸림
    {
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL)
    {   
<<<<<<< HEAD
        if(result->capacity <= result->count) {
            result->capacity = result->capacity == 0 ? 10 : result->capacity * 2;
            result->filenames = realloc(result->filenames , result->capacity * sizeof(char*));
        }
        result->filenames[result->count++] = strdup(entry->d_name);
=======
        assert(strlen(entry->d_name) < FILE_NAME_MAX); //리눅스 파일명 최대길이 255
        append_file_name(&dir_head, entry->d_name);
>>>>>>> f8dead3f35d9c74a1f776470fc98f6e68f2c1d71
    }

    if (closedir(dir) == -1)
    {
        printf("close directory failed.\n");
    }

    return dir_head;
}

FileList *make_new_node() {
    FileList *new = (FileList*)malloc(sizeof(FileList));
    memset(new->filename , 0 , FILE_NAME_MAX);
    new->next = NULL;

    return new;
}


void append_file_name(FileList **dir_head, char *file_name) {
    FileList *new = make_new_node();
    strncpy(new->filename , file_name, strlen(file_name)+1);
    new->filename[strlen(file_name)] = '\0';

    if (*dir_head == NULL) {
        *dir_head = new;
    } else {
        FileList *current = *dir_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
    }
}

void free_file_list(FileList *dir_head)
{   
    while(dir_head != NULL) {
        FileList * tmp_head = dir_head->next;
        free(dir_head);
        dir_head = tmp_head;
    }
}

void print_list(FileList *list){ //for test
    FileList * tmp = list;
    while(tmp!=NULL) {
        printf("%s\n", tmp->filename);
        tmp = tmp->next;
    }
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

void find(const char *path, const char *file_name)
{   

    FileList * file_head = ls_cmd(path);
    if(file_head == NULL) {
        return;
    }
    
    struct stat file_stat;
    char current_file_path[PATH_MAX];
<<<<<<< HEAD
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
=======
    FileList *tmp_list = file_head;
    while(tmp_list!=NULL) {
        const char *current_file_name = (const char*)tmp_list->filename;
        if (strcmp(current_file_name , ".") && strcmp(current_file_name , "..")) {
            concat_path(path, current_file_name, current_file_path);
            //printf("%s\n", current_file_path);
            if (lstat(current_file_path, &file_stat) == 0) {
                if (S_ISDIR(file_stat.st_mode)) {
                    find(current_file_path, file_name);
                } else if(!strcmp(current_file_name , file_name)) {
                    printf("%s\n",current_file_path);
                    found_count ++;
                }
            } else {
                //printf("%s - stat failed: %s\n", current_file_path, strerror(errno));
                //보류
>>>>>>> f8dead3f35d9c74a1f776470fc98f6e68f2c1d71
            }
        }
        tmp_list = tmp_list->next;
    }
    free_file_list(file_head);
}
