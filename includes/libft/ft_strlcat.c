/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:42:35 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 18:47:07 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Concatenate strings respectively.					      *
 * Take the full size of the buffer (not just the length) and guarantee to    *
 * NUL-terminate the result (as long as there is at least one byte free in dst)
 * BOth src and dst must be NUL-terminated 				      *
 * Returns the total length of the string they tried to create, that means    *
 * the initial lenth of dest plus length of src. 			      */	

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;
	size_t	j;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size <= dest_len)
		return (src_len + size);
	i = dest_len;
	j = 0;
	while (src[j] && (i < size - 1) && (size > 0))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_len + dest_len);
}
