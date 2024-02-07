/*
** EPITECH PROJECT, 2023
** reverse
** File description:
** reverse list
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

int my_struct_len(struct dir *buffer)
{
    int compt;

    for (compt = 0; buffer[compt].name; compt++);
    return compt - 1;
}

void reverse_array(struct dir *buffer, struct flags *flags)
{
    struct dir temp;
    int len = my_struct_len(buffer);

    if (flags->r == 0)
        return;
    for (int index = 0; index < len; index++) {
        temp = buffer[index];
        buffer[index] = buffer[len];
        buffer[len] = temp;
        len--;
    }
}
