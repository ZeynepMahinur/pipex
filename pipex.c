#include "pipex.h"

int child_cmd1(t_pipex *pipex, char *file1, char *cmd, char **envp)
{
    char    *args[2];
    char    *path;

    args[0] = cmd;
    args[1] = NULL;
    pipex->infile = open(file1, O_RDONLY);
    if (pipex->infile < 0)
    {
        perror("Error opening infile.");
        exit(1);
    }
    dup2(pipex->infile, 0);
    dup2(pipex->fd[1], 1);
    close(pipex->fd[0]);
    close(pipex->fd[1]);
    execve(cmd, args , envp);
    perror("Execve failed");
    exit (1);
}

int child_cmd2(t_pipex *pipex, char *file2, char *cmd, char **envp)
{
    char **args;

    args = ft_split(cmd, ' ');
    pipex->outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (pipex->outfile < 0)
    {
        perror("Error opening outfile");
        exit (1);
    }
    dup2(pipex->outfile, 1);
    dup2(pipex-> fd[0], 0);
    close(pipex->fd[1]);
    close(pipex->fd[0]);
    execve(args[0], args, envp);
    perror("Execve failed");
    exit (1);
}

int main(int argc, char **argv, char **envp)
{
    t_pipex pipex;
    pipe(pipex.fd);
    if (fork() == 0)
        child_cmd1(&pipex, "file1.txt", "grep a1", envp);
    else
        child_cmd2(&pipex, "file2.txt", "wc -w", envp);
}