/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:02:04 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/29 12:22:24 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// error.c
# define INVALID_ARG "Not enough arguments\n"
# define CORRECT_TYPE "Usage : \n./pipex file1 cmd1 cmd2  ... file2\n"

# define OPEN_ERROR "infile open failed\n"
# define PIPE_ERROR "pipe faied\n"
# define FORK_ERROR "fork failed\n"
# define MALLOC_ERROR "malloc failed\n"
# define DUP2_STDIN_ERROR "dup2 failed: prev_fd -> stdin\n"
# define DUP2_STDOUT_ERROR "dup2 failed: pipe write -> stdout\n"

// child_process.c
# define CMD_NOT_FOUND "command not found\n"
# define EXECVE_ERROR "execve failed\n"
# define INVA_CMD "invalid command\n"
# define _ENOENT " No such file or directory\n"
# define _EACCES "Permission denied\n"

#endif