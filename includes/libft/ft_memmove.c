/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:42:09 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:41:42 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Copy memory area							      *	
 * COpies n bytes from memory area src to memory area dest. The memory area   *
 * may overlap: copying takes place as though the bytes in src are first      *
 * copied into a temporary array that does not overlap src or dest, and the   *
 * bytes are then copied from the temporary array to dest		      */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	if (d == s)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
