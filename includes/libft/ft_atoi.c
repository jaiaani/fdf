/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:14:58 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:11:14 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Convert a string to an interger					      *	
 * Convertes the initial portion of the string pointed to by nptr to int.     *
 * Does not detect errors.						      *
 * Return the converted value or 0 on error				      */

#include "libft.h"

static int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	is_signal(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(char *nptr)
{
	int		x;
	int		s;
	size_t	i;

	x = 0;
	i = 0;
	s = 1;
	while (nptr[i] && is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
		s = -1;
	if (is_signal(nptr[i]))
		i++;
	while (ft_isdigit(nptr[i]))
	{
		x = x * 10 + (nptr[i] - '0');
		i++;
	}
	x *= s;
	return (x);
}
