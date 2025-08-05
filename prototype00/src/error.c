/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:31:33 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/05 19:16:14 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	invalid_usage(void)
{
	ft_putstr_fd(INVALID_ARG, STDIN_FILENO);
	ft_putstr_fd(CORRECT_TYPE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
