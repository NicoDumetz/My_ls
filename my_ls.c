/*
** EPITECH PROJECT, 2023
** my ls
** File description:
** recoding ls in c with parameters -alRdrt
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

static void add_information(struct flags *flags,
    struct dir *buffer, DIR* fd, char *path)
{
    int i;
    struct dirent *entity;

    entity = readdir(fd);
    for (i = 0; entity != NULL;) {
        if ( entity->d_name[0] == '.' && flags->a == 0)
            entity = readdir(fd);
        else {
            buffer[i].d = entity->d_type == 4 ? 'd' : '-';
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

static char *get_av(char **av, char *path, struct flags *flags)
{
    int bo = 0;

    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-') {
            path = av[i];
            bo = 1;
        } else
            get_flags(av[i], flags);
    }
    if ( bo == 0)
        path = ".";
    return path;
}

int my_ls(int ac, char **av)
{
    DIR* fd;
    struct dir *buffer;
    struct flags flags;
    char *path = get_av(av, path, &flags);

    fd = opendir(path);
    buffer = malloc(sizeof(struct dir) * 500000);
    add_information(&flags, buffer, fd, path);
    display(buffer, &flags, path);
    closedir(fd);
    free(buffer);
    return 1;
}

int main(int ac, char **av)
{
    my_ls(ac, av);
    return 0;
}
