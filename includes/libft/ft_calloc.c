/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:17:55 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:41:27 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* A memory allocator							      *	
 * Shall allocate unused space for an array of 'nelem' elements each of whose *
 * size in byte is 'elsize'. The space shall be initialized to all bits 0.    */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	tsize;
	void	*space;

	if (nelem == 0 || elsize == 0)
		return (NULL);
	tsize = nelem * elsize;
	if (tsize / elsize != nelem)
		return (NULL);
	space = malloc(tsize);
	if (!space)
		return (NULL);
	ft_bzero(space, tsize);
	return (space);
}
