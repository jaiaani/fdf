/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:03:43 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:07:03 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compare memory areas							      *
 * Compares the first n bytes (each interpreted as unsigned char) of 	      *
 * the memory s1 and s2							      
 * Returns an integer less than, equal to, or greater than zero if the 
 *  first n bytes of s1 is found, respectively, to be less than, to match, 
 *  or be greater than the first n bytes of s2.
 * For a nonzero return value, the sign is determined by the sign of the 
 * 	difference between the first pair of bytes (interpreted as unsigned char)
 * 	that differ in s1 and s2.
 * If n is zero, the return value is zero.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (n == 0)
		return (0);
	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
