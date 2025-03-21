/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:17:26 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 18:35:40 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Zero a byte string							      *
 * Erases the data in the n bytes of the memory	starting at the location      *
 * pointed to by s, by writing zeros (bytes containing '\0') to that area     */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = '\0';
}
