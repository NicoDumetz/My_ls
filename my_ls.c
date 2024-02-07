/*
** EPITECH PROJECT, 2023
** my ls
** File description:
** recoding ls in c with parameters -alRdrt
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

int error(DIR* fd, char *path)
{
    if (fd == NULL) {
        my_printf("ls: cannot access '%s': %s\n", path, strerror(errno));
        exit(0);
        return 84;
    }
}

static char get_type(struct dirent *entity)
{
    if (entity->d_type == 8)
        return '-';
    if (entity->d_type == 4)
        return 'd';
    if (entity->d_type == 1)
        return 'p';
    if (entity->d_type == 12)
        return 's';
    if (entity->d_type == 10)
        return 'l';
    if (entity->d_type == 6)
        return 'b';
    if (entity->d_type == 2)
        return 'c';
    if (entity->d_type == 0)
        return '?';
}

static int add_information(struct flags *flags,
    struct dir *buffer, DIR* fd, char *path)
{
    int i;
    struct dirent *entity;

    entity = readdir(fd);
    for (i = 0; entity != NULL;) {
        if ((entity->d_name[0] == '.' && flags->a == 0 && flags->d == 0))
            entity = readdir(fd);
        else {
            buffer[i].d = get_type(entity);
            buffer[i].name = entity->d_name;
            buffer[i].reclen = entity->d_reclen;
            add_perm(entity, buffer, i, path);
            entity = readdir(fd);
            i++;
        }
    }
    buffer[i].name = 0;
}

static void get_flags(char *str, struct flags *flags)
{
    for (int k = 0; str[k]; k++) {
        flags->a += str[k] == 'a' ? 1 : 0;
        flags->l += str[k] == 'l' ? 1 : 0;
        flags->R += str[k] == 'R' ? 1 : 0;
        flags->d += str[k] == 'd' ? 1 : 0;
        flags->r += str[k] == 'r' ? 1 : 0;
        flags->t += str[k] == 't' ? 1 : 0;
    }
}

static int get_size(char *path)
{
    int i;
    struct dirent *entity;
    DIR* fd;

    fd = opendir(path);
    if (error(fd, path) == 84)
        return 84;
    entity = readdir(fd);
    for (i = 0; entity != NULL; i++) {
        entity = readdir(fd);
    }
    return i;
}

int my_ls(char *path, struct flags *flags, int plus)
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
    return 1;
}

static char *get_av(char **av)
{
    int bo = 0;
    int compt = 0;
    struct flags flags;

    for (int k = 1; av[k]; k++) {
        if (av[k][0] == '-')
            get_flags(av[k], &flags);
        else {
            compt += 1;
            bo = 1;
        }
    }
    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-' && compt <= 1)
            my_ls(av[i], &flags, 0);
        if (av[i][0] != '-' && compt > 1)
            my_ls(av[i], &flags, 1);
    }
    if ( bo == 0)
        my_ls(".", &flags, 0);
}

int main(int ac, char **av)
{
    get_av(av);
    return 1;
}
