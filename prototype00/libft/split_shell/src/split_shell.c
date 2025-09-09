/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iokuno <iokuno@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 03:28:41 by iokuno            #+#    #+#             */
/*   Updated: 2025/09/09 11:53:58 by iokuno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// split_shell.c
#include "split_shell.h"

static int	convert_tokens_freeable(t_vec *vec)
{
	size_t	j;

	j = 0;
	while (j < vec->idx - 1)
	{
		vec->vec[j] = freeable(vec->vec[j]);
		if (!vec->vec[j])
		{
			while (j > 0)
			{
				j--;
				free(vec->vec[j]);
			}
			my_meta_free(vec->vec);
			return (-1);
		}
		j++;
	}
	return (0);
}

char	**split_shell(const char *s)
{
	size_t	i;
	t_vec	vec;
	char	*tok;

	if (!s || !balanced_quotes(s))
		return (error_mes(_EINVAL), NULL);
	i = 0;
	vec.vec = NULL;
	vec.idx = 0;
	vec.cap = 0;
	skip_set(s, &i);
	while (s[i])
	{
		tok = read_token(s, &i);
		if (!tok || vec_push(&vec, tok) < 0)
			return (my_meta_free(tok), all_free(vec.vec), NULL);
		skip_set(s, &i);
	}
	if (vec_push(&vec, NULL) < 0)
		return (NULL);
	if (convert_tokens_freeable(&vec) < 0)
		return (NULL);
	return (freeable(vec.vec));
}
