/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:45:25 by zarikan           #+#    #+#             */
/*   Updated: 2025/09/03 12:45:40 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**find_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	if (!cmd || !*cmd)
	{
		ft_printf("Non-existant command\n");
		exit(127);
	}
	args = ft_split(cmd, ' ');
	if (!args)
		exit(1);
	path = cmd_path(args[0], envp);
	if (!path)
	{
		free_split(args);
		exit(127);
	}
	free(args[0]);
	args[0] = path;
	return (args);
}

static void	child_cmd1(t_pipex *pipex, char *file1, char *cmd, char **envp)
{
	char	**args;

	args = find_cmd(cmd, envp);
	pipex->infile = open(file1, O_RDONLY);
	if (pipex->infile < 0)
	{
		perror("Error opening infile.");
		free_split(args);
		exit(1);
	}
	dup2(pipex->infile, 0);
	dup2(pipex->fd[1], 1);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	execve(args[0], args, envp);
	perror("Execve failed");
	free_split(args);
	exit(127);
}

static void	child_cmd2(t_pipex *pipex, char *cmd, char *file2, char **envp)
{
	char	**args;

	pipex->outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile < 0)
		exit (1);
	args = find_cmd(cmd, envp);
	dup2(pipex->outfile, 1);
	dup2(pipex->fd[0], 0);
	close(pipex->fd[1]);
	close(pipex->fd[0]);
	if (execve(args[0], args, envp) == -1)
	{
		free_split(args);
		exit (127);
	}
}

static void	connect_children(t_pipex *pipex, char *argv[], char **envp)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
		child_cmd1(pipex, argv[1], argv[2], envp);
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
		child_cmd2(pipex, argv[3], argv[4], envp);
	close (pipex->fd[0]);
	close (pipex->fd[1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status1;
	int		status2;

	if (argc != 5)
	{
		ft_printf("Use: ./pipex file1 cmd1 cmd2 file2\n");
		return (1);
	}
	if (pipe(pipex.fd) == -1)
	{
		perror("Pipe failed");
		exit (1);
	}
	connect_children(&pipex, argv, envp);
	waitpid(pipex.pid1, &status1, 0);
	waitpid(pipex.pid2, &status2, 0);
	if (WIFEXITED(status2))
		return (WEXITSTATUS(status2));
	return (0);
}
