#include "pipex.h"

void free_split(char **arr)
{
    size_t  i;

    i = 0;
	while (arr[i])
	{
		free(arr[i++]);
	}
	free(arr);
}

char    *cmd_path(char *cmd, char **envp)
{
    int     i;
    char    *tmp;
    char    **paths;
    char    *total_path;

    i = 0;
    while(envp[i] && ft_strncmp(envp[i], "PATH=", 5))
        i++;
    if (!envp[i])
        return (NULL);
    paths = ft_split(envp[i] + 5, ':');
    i = 0;
    while (paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        total_path = ft_strjoin(tmp, cmd);
        free (tmp);
        if (access(total_path, X_OK) == 0)
        {
            free_split(paths);
            return (total_path);
        }
        free (total_path);
        i++;
    }
    free_split(paths);
    return (NULL);
}