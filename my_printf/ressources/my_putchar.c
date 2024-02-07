/*
** EPITECH PROJECT, 2023
** putchar
** File description:
** put a char (emoji chokbar de bz)
*/
#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
