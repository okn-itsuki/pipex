/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:49:52 by oitsuki           #+#    #+#             */
/*   Updated: 2025/08/29 11:16:29 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, const char **av, const char **envp)
{
	t_ctx	*ctx;

	ctx = NULL;
	if (ac < 5)
		invalid_usage();
	ctx = init_ctx(ctx, ac, av, envp);
	run_pipex(ctx);
	return (EXIT_SUCCESS);
}
