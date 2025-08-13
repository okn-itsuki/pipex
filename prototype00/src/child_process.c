/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:57:15 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/14 05:55:50 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *cmd, char **envp)
{
	char **args;
	char *path;

	// "grep foo" → ["grep", "foo", NULL]
	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		ft_free_split(args);
		perror(INVA_CMD);
		exit(EXIT_FAILURE);
	}

	// 実行ファイルの絶対パスを探す（例: /bin/grep）
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		ft_free_split(args);
		perror(CMD_NOT_FOUND);
		exit(EXIT_FAILURE);
	}

	// コマンド実行（成功すればこの先のコードには戻らない）
	if (execve(path, args, envp) == -1)
	{
		free(path);
		ft_free_split(args);
		perror(EXECVE_ERROR);
		exit(EXIT_FAILURE);
	}
}