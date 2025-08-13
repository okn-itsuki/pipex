/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:57:44 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/13 22:09:33 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	last_cmd(t_ctx *ctx, int prev_fd, int arg_i)
{
	int	output_fd;

	output_fd = open(ctx->av[ctx->ac - 1], O_CREAT | O_WRONLY | O_TRUNC,
			PERM_644);
	if (output_fd < 0)
		error_exit(OPEN_ERROR);
	ctx->pid = fork();
	if (ctx->pid == -1)
		error_exit(FORK_ERROR);
	if (ctx->pid == 0)
	{
		dup2(prev_fd, 0);
		dup2(output_fd, 1);
		child_process(ctx->av[arg_i], ctx->envp);
	}
}

static void	fork_pipex(t_ctx *ctx, int prev_fd, int arg_i)
{
	ctx->pid = fork();
	if (ctx->pid == -1)
		error_exit(FORK_ERROR);
	if (ctx->pid == 0)
	{
		if (dup2(prev_fd, STDIN_FILENO) == -1)
			error_exit(DUP2_STDIN_ERROR);
		if (dup2(ctx->pipe_fd[1], STDOUT_FILENO) == -1)
			error_exit(DUP2_STDOUT_ERROR);
		close(ctx->pipe_fd[0]);
		child_process(ctx->av[arg_i], ctx->envp);
	}
}

void	run_pipex(t_ctx *ctx)
{
	int	arg_i;
	int	prev_fd;

	prev_fd = ctx->infile;
	arg_i = 2;
	while (arg_i < (ctx->ac - 2))
	{
		if (pipe(ctx->pipe_fd) == -1)
			error_exit(PIPE_ERROR);
		fork_pipex(ctx, prev_fd, arg_i);
		close(ctx->pipe_fd[1]);
		if (prev_fd != ctx->infile)
			close(prev_fd);
		prev_fd = ctx->pipe_fd[0];
		waitpid(ctx->pid, NULL, 0);
		arg_i++;
	}
	last_cmd(ctx, prev_fd, arg_i);
	close(prev_fd);
	close(ctx->outfile);
	waitpid(ctx->pid, NULL, 0);
}
