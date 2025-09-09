/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:49:52 by oitsuki           #+#    #+#             */
/*   Updated: 2025/09/01 03:34:56 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, const char **av, const char **envp)
{
	t_ctx	*ctx;

	ctx = NULL;
	if (ac < 5)
		invalid_usage();
	check_cmd_null(ac, av);
	ctx = init_ctx(ctx, ac, av, envp);
	run_pipex(ctx);
	return (EXIT_SUCCESS);
}
