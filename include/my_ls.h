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
    #include <errno.h>
    #include <string.h>
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
    int total;
    int mtime;
    char *readlink;
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
int my_strcmp_alpha(char const *s1, char const *s2);
int add_perm(struct dirent *entity, struct dir *buffer, int i, char *path);
void display(struct dir *buffer, struct flags *flags, char *path, int plus);
void reverse_array(struct dir *buffer, struct flags *flags);
int my_sort_array_time(struct dir *buffer, struct flags *flags);
int my_strcmp_time(int s1, int s2);
int add_perm_d(struct dir *disp_d, char *path);
int my_ls_file(char *path, struct flags *flags, int plus);
void disp_d(struct flags *flags, char *path, int d);
char get_type(struct dirent *entity);
int flags_r(char *path, struct flags *flags, int plus);
int add_information(struct flags *flags,
    struct dir *buffer, DIR* fd, char *path);
int get_size(char *path);
int my_strcmp(char const *s1, char const *s2);
char *set_path(char *path_files, char *path, struct dirent *entity);
int len_array(struct dir *tab);
#endif
