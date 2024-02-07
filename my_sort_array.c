/*
** EPITECH PROJECT, 2023
** MY SORT WORD ARRAY
** File description:
** Write a function that, using ascii order, sorts the words
** received via my_str_to_word_array. The sort should
** be executed by switching the array’s pointers
*/

#include "include/my_ls.h"
#include "include/my_printf.h"

int len_array(struct dir *tab)
{
    int compt;

    for (compt = 0; tab[compt].name; compt++) {
    }
    return compt;
}

int my_sort_array(struct dir *buffer)
{
    struct dir temp;
    int index = 0;
    int ac = len_array(buffer);

    for ( index = 0; index < ac - 1;) {
        if ( my_strcmp_alpha(buffer[index].name,
            buffer[index + 1].name) == 1) {
            temp = buffer[index];
            buffer[index] = buffer[index + 1];
            buffer[index + 1] = temp;
            index = 0;
        } else {
            index++;
        }
    }
    return 0;
}

int my_sort_array_time(struct dir *buffer, struct flags *flags)
{
    struct dir temp;
    int index = 0;
    int ac = len_array(buffer);

    if (flags->t == 0)
        return 0;
    for ( index = 0; index < ac - 1;) {
        if ( my_strcmp_time(buffer[index].mtime,
            buffer[index + 1].mtime) == 1) {
            temp = buffer[index];
            buffer[index] = buffer[index + 1];
            buffer[index + 1] = temp;
            index = 0;
        } else {
            index++;
        }
    }
    return 0;
}
