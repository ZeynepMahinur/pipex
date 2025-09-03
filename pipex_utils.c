/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zarikan <zarikan@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 12:52:11 by zarikan           #+#    #+#             */
/*   Updated: 2025/09/03 12:52:27 by zarikan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}

char	*find_cmd_path(char *cmd, char **paths)
{
	char	*tmp;
	char	*total_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		total_path = ft_strjoin(tmp, cmd);
		free (tmp);
		if (access(total_path, X_OK) == 0)
			return (total_path);
		free (total_path);
		i++;
	}
	return (NULL);
}

char	*cmd_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*result;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	result = find_cmd_path(cmd, paths);
	free_split(paths);
	return (result);
}
