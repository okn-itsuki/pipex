/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_invalid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:31:33 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/04 07:10:01 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	invalid_usage(int ac)
{
	if (ac < 5)
	{
		ft_putstr_fd("error : not enough arguments\n\n", STDIN_FILENO);
		ft_putstr_fd("Correct type \n$/ ./pipex file1 cmd1 cmd2 file2\n",
			STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (1);
}