
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define bool int
#define false 0
#define ture 1

bool is_dir(const char *path)
{
    struct stat statbuf;
    if (lstat(path, &statbuf) == 0)
    {
        return S_ISDIR(statbuf.st_mode) != 0;
    }
    return false;
}

bool is_file(const char *path)
{
    struct stat statbuf;
    if (lstat(path, &statbuf) == 0)
        return S_ISREG(statbuf.st_mode) != 0;
    return false;
}

bool is_special_dir(const char *path)
{
    return strcmp(path, ".") == 0 || strcmp(path, "..") == 0;
}

void get_file_path(const char *path, const char *file_name, char *file_path)
{
    strcpy(file_path, path);
    if (file_path[strlen(path) - 1] != '/')
        strcat(file_path, "/");
    strcat(file_path, file_name);
}

int delete_file(const char *path)
{
    int ret = -1;  
    DIR *dir = NULL;
    struct dirent *dir_info;
    char file_path[PATH_MAX];
    if(path == NULL)
    {
        printf("path is NULL\n");
    }
    printf("path: %s!\n",path);
    if (is_file(path))
    {
        ret = remove(path);
        printf("remove file (%s):%d\n",path, ret);
        return ret;
    }
    if (is_dir(path))
    {
        if ((dir = opendir(path)) == NULL)
        {
            printf("opendir fail!\n");
            return -1;
        }
        while ((dir_info = readdir(dir)) != NULL)
        {
            get_file_path(path, dir_info->d_name, file_path);
            if (is_special_dir(dir_info->d_name))
                continue;
            ret = delete_file(file_path);
            if(ret == 1)
            {
                    printf("rmdir dir (%s):%d\n",file_path, rmdir(file_path));
             }
        }
        return 1;
    }
    return -1;
}
int main(int argc, char **argv)
{
    int ret = -1;
    char* path = "/home/flycba/111";
    ret  = delete_file(path); 
    if(1 == ret)
    {
        printf("rmdir dir (%s):%d\n",path, rmdir(path));
    }
    printf("ret :%d",ret);
    return 0;
}
