/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:46:17 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:33:36 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates with mallloc() and returns a string represenyting the integer    *
 * received as an argument. Negative numbers must be handled     	      *
 * n: the number to convert						      */

#include "libft.h"

static int	number_length(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*a;
	int		nlen;
	int		s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	s = (n < 0);
	nlen = number_length(n);
	a = (char *) malloc ((nlen + 1) * sizeof(char));
	if (!a)
		return (NULL);
	a[nlen] = '\0';
	if (s)
	{
		a[0] = '-';
		n = -n;
	}
	while (--nlen >= s)
	{
		a[nlen] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}
