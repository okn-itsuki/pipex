/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:53:02 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/29 12:05:48 by iokuno           ###   ########.fr       */
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
