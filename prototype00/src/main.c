/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:49:52 by oitsuki           #+#    #+#             */
/*   Updated: 2025/07/30 04:54:33 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	while (**envp)
	{
		if (strncmp("PATH=", *envp, 5) == 0)
		{
			return (ft_split(*envp, ':'));
		}
		envp++;
	}
	return (NULL);
}

int	main(int ac, const char **av, const char **envp)
{
	const char	*path_line = find_path(envp);

	(void)ac;
	(void)av;
	printf("%s\n", path_line);
	return (EXIT_SUCCESS);
}
