/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:49:52 by oitsuki           #+#    #+#             */
/*   Updated: 2025/08/05 19:16:10 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, const char **av, const char **envp)
{
	t_ctx	*ctx;

	if (ac < 5)
		invalid_usage();
	ctx = init_ctx(ctx, ac, av, envp);
	run_pipex(ctx);
	for (int i = 0; i < ac; i++)
		printf("%s ", av[i]);
	return (EXIT_SUCCESS);
}

// find_path test main

// int	main(int ac, char **av, const char **envp)
// {
// 	char	**path;

// 	(void)ac;
// 	(void)av;
// 	path = find_path(envp);
// 	ft_print_split(path);
// 	return (EXIT_SUCCESS);
// }
