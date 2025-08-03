/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:51:40 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/04 07:10:05 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(const char **envp)
{
	while (**envp)
	{
		if (ft_strncmp("PATH=", *envp, 5) == 0)
		{
			return (ft_split(*envp, ':'));
		}
		envp++;
	}
	return (NULL);
}
