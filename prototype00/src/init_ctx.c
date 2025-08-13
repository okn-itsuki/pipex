/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ctx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:05:46 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/13 22:11:22 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_ctx	*init_ctx(t_ctx *ctx, int ac, const char **av, const char **envp)
{
	ctx = malloc(sizeof(t_ctx));
	if (!ctx)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	ctx->ac = ac;
	ctx->av = (char **)av;
	ctx->envp = (char **)envp;
	ctx->infile = open(av[1], O_RDONLY);
	if (ctx->infile < 0)
		perror(av[1]);
	ctx->outfile = open(av[ac - 1], O_CREAT | O_WRONLY | O_TRUNC, PERM_644);
	if (ctx->outfile < 0)
		perror(av[ac - 1]);
	ctx->pipe_fd[0] = -1;
	ctx->pipe_fd[1] = -1;
	ctx->pid = -1;
	return (ctx);
}
