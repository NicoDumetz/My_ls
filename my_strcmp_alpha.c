/*
** EPITECH PROJECT, 2023
** lfsgzep
** File description:
** sdvlnslkbdlkn
*/
#include "include/my_ls.h"
#include "include/my_printf.h"

int my_strcmp_alpha(char const *s1, char const *s2)
{
    char a;
    char b;
    int index;

    for (index = 0; s1[index] != '\0' || s2[index] != '\0'; index++) {
        a = s1[index] >= 65 && s1[index] <= 90 ? s1[index] + 32 : s1[index];
        b = s2[index] >= 65 && s2[index] <= 90 ? s2[index] + 32 : s2[index];
        if (a > b)
            return 1;
        if (b > a)
            return -1;
    }
    if ( s1[index] == '\0' && s2[index] == '\0')
        return 0;
    if (s1[index] != '\0')
        return -1;
    else
        return 1;
}

int my_strcmp_time(int s1, int s2)
{
    if (s1 < s2)
        return 1;
    if (s1 > s2)
        return -1;
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int index;

    for (index = 0; s1[index] != '\0' || s2[index] != '\0'; index++) {
        if (s1[index] > s2[index])
            return 1;
        if (s2[index] > s1[index])
            return -1;
    }
    if ( s1[index] == '\0' && s2[index] == '\0')
        return 0;
    if (s1[index] != '\0')
        return -1;
    else
        return 1;
}
