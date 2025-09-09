/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:57:15 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/09 13:55:42 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	code_from_errno(void)
{
	if (errno == ENOENT)
		return (_CMD_NOT_FIND);
	if (errno == EACCES)
		return (_CMD_INVA);
	return (1);
}

static void	cleanup_and_exit(t_ctx *ctx, char **args, char *path, int code)
{
	if (path)
		all_free(path);
	if (args)
		all_free(args);
	destroy_ctx(ctx);
	exit(code);
}

void	child_process(t_ctx *ctx, char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = split_shell(cmd);
	if (!args || !args[0])
	{
		ft_putstr_fd(INVA_CMD, STDERR_FILENO);
		cleanup_and_exit(ctx, args, NULL, _CMD_NOT_FIND);
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		ft_putstr_fd(CMD_NOT_FOUND, STDERR_FILENO);
		cleanup_and_exit(ctx, args, NULL, _CMD_INVA);
	}
	execve(path, args, envp);
	ft_putstr_fd(EXECVE_ERROR, STDERR_FILENO);
	cleanup_and_exit(ctx, args, path, code_from_errno());
}
