/*
** EPITECH PROJECT, 2018
** prompt git for 42sh
** File description:
** get the git repository branch
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"
#include "sh.h"

int get_git_branch(char *buffer)
{
    char **master = NULL;
    int len = 0;

    master = my_strtwa2(buffer, '/');
    len = my_len_array(master);
    if (master[len - 1] != NULL) {
        my_putstr("\033[1;33m");
        my_putstr(" (");
        if (my_strlen(master[len - 1]) == 6)
            my_putstr(master[len - 1]);
        else
            write(1, master[len - 1], 6);
        my_putstr(")");
        my_putstr("\033[0m");
    }
    my_free_array(master);
    return (0);
}

int read_and_print_git(int filesize, int fd)
{
    char buffer[filesize];
    int size = 0;

    size = read(fd, buffer, (filesize - 1));
    if (size == -1) {
        return (-1);
    }
    buffer[filesize - 1] = '\0';
    get_git_branch(buffer);
    return (0);
}

int find_git_branch(char *string)
{
    int fd = 0;
    int filesize;
    struct stat size;

    stat(string, &size);
    filesize = size.st_size;
    fd = open(string, O_RDONLY);
    if (fd == -1) {
        return (0);
    }
    read_and_print_git(filesize, fd);
    return (0);
}

int my_promp_check_git(void)
{
    char *string = NULL;

    string = my_strcat(getcwd(NULL, 0), "/.git/HEAD");
    find_git_branch(string);
    return (1);
}
