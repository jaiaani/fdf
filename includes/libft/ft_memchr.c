/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:02:25 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:03:13 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Scan memory for a character.						      *
 * Scans the initial n bytes of the memory area pointed to by s for the first *
 * instance of c. Both c and the bytes of the memory area pointed to by s are *
 * interpreted as unsigned char.					      *
 * Returns a pointer to the matching byte of NULL if the character does not   *
 * occur in the given memory 						      */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
