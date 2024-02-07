/*
** EPITECH PROJECT, 2023
** display.c
** File description:
** disply all folders with their parameters
*/

#include "include/my_ls.h"
#include "include/my_printf.h"

static void disp_d(struct flags *flags, char *path)
{
    my_printf("%s\n", path);
    return;
}

void display(struct dir *buffer, struct flags *flags, char *path)
{
    my_sort_array(buffer);
    reverse_array(buffer, flags);
    if ( flags->d > 0)
        return disp_d(flags, path);
    for (int i = 0; buffer[i].name; i++) {
        my_printf("%s  ", buffer[i].name);
    }
    printf("\n");
}
