/*
** EPITECH PROJECT, 2023
** ls file
** File description:
** when there are file in parsing
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

int my_ls_file(char *path, struct flags *flags, int plus)
{
    disp_d(flags, path, 0);
    return 1;
}

static int error(DIR* fd, char *path)
{
    if (fd == NULL) {
        my_printf("ls: cannot access '%s': %s\n", path, strerror(errno));
        return 84;
    }
}

static char *set_path_r(char *path_files, char *path, struct dirent *entity)
{
    my_strcat(path_files, path);
    if (path_files[my_strlen(path) - 1] != '/')
        my_strcat(path_files, "/");
    my_strcat(path_files, entity->d_name);
    return path_files;
}

static void verify_dir(struct dirent *ent, char *path,
    struct flags *flags, struct stat *info)
{
    char *new_path;

    new_path = malloc(sizeof(char) * (my_strlen(path) +
    my_strlen(ent->d_name) + 2));
    new_path[0] = '\0';
    new_path = set_path_r(new_path, path, ent);
    stat(new_path, info);
    if (ent->d_type == 4)
        flags_r(new_path, flags, 1);
    free(new_path);
}

static int after(char *path, struct flags *flags, int plus)
{
    DIR *fd;
    struct dirent *ent;
    struct stat info;

    fd = opendir(path);
    if (error(fd, path) == 84)
        return 84;
    ent = readdir(fd);
    while (ent != NULL) {
        if (my_strcmp(ent->d_name, "..") != 0 &&
            my_strcmp(ent->d_name, ".") != 0 && my_strcmp(ent->d_name, ".git"))
            verify_dir(ent, path, flags, &info);
        ent = readdir(fd);
    }
}

int flags_r(char *path, struct flags *flags, int plus)
{
    DIR* fd;
    struct dir *buffer;
    int size = get_size(path);

    fd = opendir(path);
    if (error(fd, path) == 84)
        return 84;
    buffer = malloc(sizeof(struct dir) * size);
    if (add_information(flags, buffer, fd, path) == 84)
        return 84;
    display(buffer, flags, path, plus);
    closedir(fd);
    free(buffer);
    after(path, flags, plus);
    return 1;
}
