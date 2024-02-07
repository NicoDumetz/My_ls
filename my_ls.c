/*
** EPITECH PROJECT, 2023
** my ls
** File description:
** recoding ls in c with parameters -alRdrt
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

int error(DIR* fd)
{
    if (fd == NULL) {
        my_printf("%s\n", strerror(errno));
        exit(0);
        return 84;
    }
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
            buffer[i].d = entity->d_type == 4 ? 'd' : entity->d_type == '-';
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

int my_ls(char *path, struct flags *flags)
{
    DIR* fd;
    struct dir *buffer;

    fd = opendir(path);
    if (error(fd) == 84)
        return 84;
    buffer = malloc(sizeof(struct dir) * 500000);
    if (add_information(flags, buffer, fd, path) == 84)
        return 84;
    display(buffer, flags, path);
    closedir(fd);
    free(buffer);
    return 1;
}

static char *get_av(char **av)
{
    int bo = 0;
    struct flags flags;

    for (int i = 1; av[i]; i++) {
        if (av[i][0] != '-') {
            my_ls(av[i], &flags);
            bo = 1;
        } else
            get_flags(av[i], &flags);
    }
    if ( bo == 0) {
        my_ls(".", &flags);
    }
}

int main(int ac, char **av)
{
    get_av(av);
    return 1;
}
