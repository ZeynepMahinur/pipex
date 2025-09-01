#ifndef PIPEX_H
#define PIPEX_H

#include "libft/libft.h"
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

int child_cmd1(t_pipex *pipex, char *file1, char *cmd, char **envp);
int child_cmd2(t_pipex *pipex, char *file2, char *cmd, char **envp);


#endif