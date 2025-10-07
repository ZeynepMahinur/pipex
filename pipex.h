/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:48:55 by zarikan           #+#    #+#             */
/*   Updated: 2025/09/08 18:38:00 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../pipex_folder/libft/libft.h"
# include "../pipex_folder/printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
}		t_pipex;

int		main(int argc, char **argv, char **envp);
void	free_split(char **arr);
char	*cmd_path(char *cmd, char **envp);

#endif
