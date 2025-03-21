/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:00:27 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:01:53 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Compare part of two strings						      *
 * Shall compare not more than n bytes (bytes that follow a NUL character     *	
 * are not compared) from the array pointed to by s1 to the array pointed by  *
 * s2.									      *
 * The sign of a non-zero return value is determined by the sign of the       *
 * difference between the values of the first pair of bytes (both interpreted *
 * as type unsigned char) that differ in the strings being compared.          */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
