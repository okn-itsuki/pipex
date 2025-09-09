/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:31:33 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/01 03:48:57 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	check_cmd_null(int ac, const char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			error_exit(" permission denied: ");
		i++;
	}
}

int	invalid_usage(void)
{
	ft_putstr_fd(INVALID_ARG, STDERR_FILENO);
	ft_putstr_fd(CORRECT_TYPE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
