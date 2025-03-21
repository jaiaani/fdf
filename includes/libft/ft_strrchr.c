/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:56:03 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:42:59 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* String scanning operation						      *
 * Shall locate the last occurence of c in the string pointed to by s.        *
 * The terminating NUL character is considered to be part od the string.      */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	size_t	i;

	chr = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == chr)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == chr)
		return ((char *)s + i);
	return (NULL);
}
