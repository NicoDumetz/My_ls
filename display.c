/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** disply all folders with their parameters
*/

#include "include/my_ls.h"
#include "include/my_printf.h"

static void disp_l(struct dir *buffer, int i)
{
    my_printf("%c%s%s%s. %d %s %s %4ld %s %2d %02d:%02d %s\n"
    , buffer[i].d, buffer[i].usr, buffer[i].grp, buffer[i].other
    , buffer[i].file_info, buffer[i].name_user
    , buffer[i].name_group, buffer[i].size, buffer[i].month
    , buffer[i].day, buffer[i].hour, buffer[i].min, buffer[i].name);
}

static void display_name(struct dir *buffer, struct flags *flags)
{
    int total = 0;

    if (flags->l > 0) {
        for (int k = 0; buffer[k].name; k++)
            total += buffer[k].total;
        my_printf("total %d\n", total / 2);
        for (int i = 0; buffer[i].name; i++)
            disp_l(buffer, i);
    } else {
        for (int i = 0; buffer[i].name; i++)
            my_printf("%s  ", buffer[i].name);
        my_printf("\n");
    }
}

static void disp_d(struct flags *flags, char *path, struct dir *buffer)
{
    struct dir disp_d;

    if (flags->l == 0) {
        my_printf("%s\n", path);
        return;
    }
    add_perm_d(&disp_d, path);
    my_printf("d");
    disp_d.name = path;
    disp_l(&disp_d, 0);
    return;
}

void display(struct dir *buffer, struct flags *flags, char *path)
{
    my_sort_array(buffer);
    reverse_array(buffer, flags);
    my_sort_array_time(buffer, flags);
    if ( flags->d > 0)
        return disp_d(flags, path, buffer);
    display_name(buffer, flags);
}
