/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:50:01 by oitsuki           #+#    #+#             */
/*   Updated: 2025/08/05 19:16:11 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// std
# include <err.h>
# include <stdio.h>    // perror
# include <stdlib.h>   // exit
# include <string.h>   // strerror
# include <sys/wait.h> // wait, wautpid
# include <unistd.h>   // access,dup2, execve, fork, unlink

// libft
# include "ft_printf.h"
# include "libft.h"

// pipex
# include "error.h"

# define PERM_644 0644

typedef struct s_ctx
{
	int		infile;
	int		outfile;
	int		pipe_fd[2];
	pid_t	pid;
	int		ac;
	char	**av;
	char	**envp;
}			t_ctx;

// error.c
int			invalid_usage(void);
void		error_exit(char *msg);

// find_path.c
char		**find_path(const char **envp);

// init_ctx.c
t_ctx		*init_ctx(t_ctx *ctx, int ac, const char **av, const char **envp);

// pipex.c
void		run_pipex(t_ctx *ctx);

// child_process.c
void		child_process(char *cmd, char **envp);

#endif