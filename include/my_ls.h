/*
** EPITECH PROJECT, 2023
** header
** File description:
** my_ls header
*/

#ifndef MY_LS
    #define MY_LS
    #include <errno.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
typedef struct dir {
    char *name;
    char d;
    int file_info;
    int reclen;
    char *prop;
    long size;
    char usr[4];
    char grp[4];
    char other[4];
    char *name_user;
    char *name_group;
    char month[4];
    int day;
    int hour;
    int min;
} dir;
typedef struct flags {
    int a;
    int l;
    int R;
    int d;
    int r;
    int t;
} flags;
int my_sort_array(struct dir *buffer);
//char *my_strcat(char *dest, char const *src);
int my_strcmp_alpha(char const *s1, char const *s2);
//int my_strlen(char const *str);
void add_perm(struct dirent *entity, struct dir *buffer, int i, char *path);
//int my_getnbr(char const *str);
void display(struct dir *buffer, struct flags *flags, char *path);
void reverse_array(struct dir *buffer, struct flags *flags);
#endif
