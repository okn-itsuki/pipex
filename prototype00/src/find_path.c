/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:51:40 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/14 05:55:47 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(const char **envp)
{
	while (**envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
			return (ft_split(*envp + 5, ':'));
		envp++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char *path_env = NULL;
	char **paths;
	char *full_path;
	int i;

	// すでにフルパスならそのまま使える（例: /bin/ls）
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));

	// 環境変数 PATH を探す（PATH=... の部分を取り出す）
	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
		{
			path_env = *envp + 5; // "PATH="の後ろ部分だけ使う
			break ;
		}
		envp++;
	}
	if (!path_env)
		return (NULL); // PATH がなければ終了

	// ":" 区切りで分割して複数のディレクトリにする
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);

	// 各ディレクトリについてチェック
	i = 0;
	while (paths[i])
	{
		// "/usr/bin" + "/" + "ls" = "/usr/bin/ls"
		full_path = malloc(ft_strlen(paths[i]) + ft_strlen(cmd) + 2);
		if (!full_path)
			return (ft_free_split(paths), NULL);
		sprintf(full_path, "%s/%s", paths[i], cmd);

		if (access(full_path, X_OK) == 0)
			return (ft_free_split(paths), full_path); // 実行可能なら返す

		free(full_path); // ダメなら捨てる
		i++;
	}
	ft_free_split(paths);
	return (NULL); // 見つからなかった
}