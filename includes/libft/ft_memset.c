/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:17:19 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 18:34:49 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Fill memory with a constant bytei					      *	
 * Fills the first n bytes of the memory area pointed to by s with the        *
 * constant byte c.							      */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;

	d = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		d[i] = (unsigned char) c;
		i++;
	}
	return (d);
}
