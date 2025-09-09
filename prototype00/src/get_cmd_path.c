/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:51:40 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/29 17:26:25 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **envp)
{
	int	i;

	if (!envp)
		return (NULL);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*try_absolute(char *cmd)
{
	if (!cmd)
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	return (NULL);
}

static char	*cheak_paths(char **paths, char *cmd)
{
	int		i;
	char	*joined;
	char	*full;

	i = 0;
	while (paths[i])
	{
		joined = ft_strjoin(paths[i], "/");
		if (!joined)
			return (ft_free_split(paths), NULL);
		full = ft_strjoin(joined, cmd);
		free(joined);
		if (!full)
			return (ft_free_split(paths), NULL);
		if (access(full, X_OK) == 0)
			return (ft_free_split(paths), full);
		free(full);
		i++;
	}
	ft_free_split(paths);
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*abs;

	path_env = find_path(envp);
	abs = try_absolute(cmd);
	if (abs)
		return (abs);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	return (cheak_paths(paths, cmd));
}
