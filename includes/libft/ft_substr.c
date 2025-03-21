/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:05:06 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:22:49 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Parameters:
 * s: The string from which to create the substring.
 * start: The start index of the substring in the string 's'.
 * len: The maximm length of the substring
 *
 * Returns the substring; NULL is tha allocation fails
 *
 * Allocates (with malloc(3)) and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size 'len'.
 */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	rlen;
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	rlen = ft_strlen(s + start);
	if (rlen > len)
		rlen = len;
	sub = malloc(sizeof(char) * (rlen + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, (rlen + 1));
	return (sub);
}
