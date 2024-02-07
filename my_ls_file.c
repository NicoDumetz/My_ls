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
        exit(0);
        return 84;
    }
}

static int after(char *path, struct flags *flags, int plus)
{
    DIR *fd;
    struct dirent *ent;
    struct stat info;
    char *new_path;

    return 0;
    fd = opendir(path);
    if (error(fd, path) == 84)
        return 84;
    ent = readdir(fd);
    while (ent != NULL) {
        ent = readdir(fd);
        new_path = set_path(new_path, path, ent);
        stat(new_path, &info);
        if (S_ISDIR(info.st_mode))
            flags_r(new_path, flags, plus);
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
