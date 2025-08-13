/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 09:02:04 by iokuno            #+#    #+#             */
/*   Updated: 2025/08/14 05:49:06 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

// error.c
# define INVALID_ARG "Not enough arguments\n"
# define CORRECT_TYPE "Usage : \n./pipex file1 cmd1 cmd2  ... file2\n"

# define OPEN_ERROR "infile open failed"
# define PIPE_ERROR "pipe faied"
# define FORK_ERROR "fork failed"
# define DUP2_STDIN_ERROR "dup2 failed: prev_fd -> stdin"
# define DUP2_STDOUT_ERROR "dup2 failed: pipe write -> stdout"

// child_process.c
# define
# define
# define

#endif