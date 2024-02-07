/*
** EPITECH PROJECT, 2023
** permissions files
** File description:
** set perms for all files
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

static void set_perm(struct stat *file, struct dir *buffer, int i)
{
    buffer[i].usr[0] = (file->st_mode & S_IRUSR) ? 'r' : '-';
    buffer[i].usr[1] = (file->st_mode & S_IWUSR) ? 'w' : '-';
    buffer[i].usr[2] = (file->st_mode & S_IXUSR) ? 'x' : '-';
    buffer[i].usr[3] = '\0';
    buffer[i].grp[0] = (file->st_mode & S_IRGRP) ? 'r' : '-';
    buffer[i].grp[1] = (file->st_mode & S_IWGRP) ? 'w' : '-';
    buffer[i].grp[2] = (file->st_mode & S_IXGRP) ? 'x' : '-';
    buffer[i].grp[3] = '\0';
    buffer[i].other[0] = (file->st_mode & S_IROTH) ? 'r' : '-';
    buffer[i].other[1] = (file->st_mode & S_IWOTH) ? 'w' : '-';
    buffer[i].other[2] = (file->st_mode & S_IXOTH) ? 'x' : '-';
    buffer[i].other[3] = '\0';
}

static void get_user_group(struct stat *file, struct dir *buffer, int i)
{
    struct passwd *user;
    struct group *group;

    user = getpwuid(file->st_uid);
    buffer[i].name_user = user->pw_name;
    group = getgrgid(file->st_gid);
    buffer[i].name_group = group->gr_name;
}

static void get_time(struct dir *buffer, int i, char *date)
{
    buffer[i].day = date[8] == ' ' ? my_getnbr((date + 9)) :
    my_getnbr((date + 8));
    buffer[i].hour = date[11] == ' ' ? my_getnbr((date + 12)) :
    my_getnbr((date + 11));
    buffer[i].min = my_getnbr((date + 14));
    buffer[i].month[0] = date[4];
    buffer[i].month[1] = date[5];
    buffer[i].month[2] = date[6];
    buffer[i].month[3] = '\0';
}

static int error(void)
{
    printf("%s\n", strerror(errno));
    exit(0);
    return 84;
}

static char *set_path(char *path_files, char *path, struct dirent *entity)
{
    if ( my_strlen(path) != 1) {
        my_strcat(path_files, path);
        if (path_files[my_strlen(path) - 1] != '/')
            my_strcat(path_files, "/");
    }
    my_strcat(path_files, entity->d_name);
    return path_files;
}

int add_perm(struct dirent *entity, struct dir *buffer, int i, char *path)
{
    char *path_files = malloc(sizeof(char) * (my_strlen(path) +
    my_strlen(entity->d_name) + 1));
    struct stat file;

    path_files[0] = '\0';
    path_files = set_path(path_files, path, entity);
    if (stat(path_files, &file) == -1)
        return error();
    set_perm(&file, buffer, i);
    get_user_group(&file, buffer, i);
    buffer[i].file_info = file.st_nlink;
    get_time(buffer, i, ctime(&file.st_mtime));
    buffer[i].size = file.st_size;
    buffer[i].total = file.st_blocks;
    buffer[i].mtime = file.st_mtime;
    free(path_files);
}

int add_perm_d(struct dir *disp_d, char *path)
{
    struct stat file;
    char *date;

    if (stat(path, &file) == -1)
        return error();
    set_perm(&file, disp_d, 0);
    get_user_group(&file, disp_d, 0);
    disp_d[0].file_info = file.st_nlink;
    get_time(disp_d, 0, ctime(&file.st_mtime));
    disp_d[0].size = file.st_size;
    disp_d[0].total = file.st_blocks;
    disp_d[0].mtime = file.st_mtime;
}
