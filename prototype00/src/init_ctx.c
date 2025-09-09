/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:05:46 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/09 13:37:54 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	destroy_ctx(t_ctx *ctx)
{
	if (!ctx)
		return ;
	if (ctx->infile >= 0)
		close(ctx->infile);
	if (ctx->outfile >= 0)
		close(ctx->outfile);
	free(ctx);
}

void	errer_open(t_ctx *ctx, const char **av, int idx)
{
	perror(av[idx]);
	destroy_ctx(ctx);
	exit(EXIT_FAILURE);
}

t_ctx	*init_ctx(t_ctx *ctx, int ac, const char **av, const char **envp)
{
	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
	{
		perror(MALLOC_ERROR);
		exit(EXIT_FAILURE);
	}
	ctx->ac = ac;
	ctx->av = (char **)av;
	ctx->envp = (char **)envp;
	ctx->infile = open(av[1], O_RDONLY);
	if (ctx->infile < 0)
		errer_open(ctx, av, ac);
	ctx->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, PERM_644);
	if (ctx->outfile < 0)
		errer_open(ctx, av, (ac - 1));
	ctx->pipe_fd[0] = -1;
	ctx->pipe_fd[1] = -1;
	ctx->pid = -1;
	return (ctx);
}
