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
