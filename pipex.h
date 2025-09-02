#ifndef PIPEX_H
#define PIPEX_H

#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

typedef struct  s_pipex
{
    int infile;
    int outfile;
    int fd[2];
    pid_t pid1;
    pid_t pid2;
}               t_pipex;

int main(int argc, char **argv, char **envp);
void **free_split(char **arr);
char    *cmd_path(char *cmd, char **envp);


#endif