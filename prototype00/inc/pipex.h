/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:50:01 by oitsuki           #+#    #+#             */
/*   Updated: 2025/08/04 07:10:00 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// libft
# include "ft_printf.h"
# include "libft.h"

// pipex
# include "error.h"

// std
# include <err.h>
# include <stdio.h>    // perror
# include <stdlib.h>   // exit
# include <string.h>   // strerror
# include <sys/wait.h> // wait, wautpid
# include <unistd.h>   // access, dup, dup2, execve, fork, unlink

int		invalid_usage(int ac);
char	**find_path(const char **envp);

#endif