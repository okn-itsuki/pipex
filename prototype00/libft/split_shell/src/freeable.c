/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:23:00 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/09 08:11:00 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_shell.h"

void	*freeable(void *ptr)
{
	void	*new_ptr;
	size_t	old_size;
	t_block	*old_block;

	if (ptr == NULL)
		return (NULL);
	old_block = ((t_block *)ptr) - 1;
	old_size = old_block->size;
	new_ptr = malloc(old_block->size);
	if (new_ptr == NULL)
		return (NULL);
	my_memcpy(new_ptr, ptr, old_size);
	my_meta_free(ptr);
	return (new_ptr);
}
