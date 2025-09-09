/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 08:57:44 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/09 13:25:57 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	last_cmd(t_ctx *ctx, int prev_fd, int arg_i)
{
	int	output_fd;

	output_fd = open(ctx->av[ctx->ac - 1], O_CREAT | O_WRONLY | O_TRUNC,
			PERM_644);
	if (output_fd < 0)
		perror(OPEN_ERROR);
	ctx->pid = fork();
	if (ctx->pid == -1)
		error_exit(FORK_ERROR);
	if (ctx->pid == 0)
	{
		if (dup2(prev_fd, STDIN_FILENO) == -1)
			error_exit(DUP2_STDIN_ERROR);
		if (dup2(output_fd, STDOUT_FILENO) == -1)
			error_exit(DUP2_STDOUT_ERROR);
		if (prev_fd >= 0)
			close(prev_fd);
		if (output_fd >= 0)
			close(output_fd);
		child_process(ctx, ctx->av[arg_i], ctx->envp);
		error_exit(EXECVE_ERROR);
	}
	if (output_fd >= 0)
		close(output_fd);
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
		if (prev_fd >= 0)
			close(prev_fd);
		close(ctx->pipe_fd[1]);
		close(ctx->pipe_fd[0]);
		child_process(ctx, ctx->av[arg_i], ctx->envp);
		error_exit(EXECVE_ERROR);
	}
}

static void	spawn_stage(t_ctx *ctx, int *prev_fd, int arg_i)
{
	int	ret;

	ret = pipe(ctx->pipe_fd);
	if (ret == -1)
		error_exit(PIPE_ERROR);
	fork_pipex(ctx, *prev_fd, arg_i);
	close(ctx->pipe_fd[1]);
	close_if_needed(*prev_fd, ctx->infile);
	*prev_fd = ctx->pipe_fd[0];
}

static int	wait_children(pid_t last_pid)
{
	int		status;
	pid_t	wait_pid;
	int		exit_code;

	exit_code = 0;
	wait_pid = wait(&status);
	while (wait_pid > 0)
	{
		if (wait_pid == last_pid)
			exit_code = (status >> 8) & 0b11111111;
		wait_pid = wait(&status);
	}
	return (exit_code);
}

void	run_pipex(t_ctx *ctx)
{
	int	arg_i;
	int	prev_fd;
	int	exit_code;

	prev_fd = ctx->infile;
	arg_i = 2;
	while (arg_i < ctx->ac - 2)
	{
		spawn_stage(ctx, &prev_fd, arg_i);
		arg_i++;
	}
	last_cmd(ctx, prev_fd, arg_i);
	if (prev_fd >= 0)
		close(prev_fd);
	exit_code = wait_children(ctx->pid);
	destroy_ctx(ctx);
	exit(exit_code);
}
