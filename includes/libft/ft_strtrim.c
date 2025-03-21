/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 03:49:54 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:43:47 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates with malloc() and returns a copy of 's1' with the characters     *
 * specified in 'set' removed from the beginning and the end of the string    *
 * s1: The string to be trimmed						      *
 * set: The reference set of characters to trim				      */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	b;
	size_t	e;
	size_t	qnty;

	if (!s1 || !set)
		return (NULL);
	b = 0;
	e = ft_strlen(s1) - 1;
	while (is_set(set, s1[b]))
		b++;
	while (is_set(set, s1[e]) && e > b)
		e--;
	qnty = e - b + 1;
	if (qnty == 0)
		return (ft_strdup(""));
	return (ft_substr(s1, b, qnty));
}
