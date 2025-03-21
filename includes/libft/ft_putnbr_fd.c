/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:39:48 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:42:15 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the integer 'n' to the given file descriptor 		      *
 * n: the integer to output | fd: The file descriptor on which to write       */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	s;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	s = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		s = -1;
	}
	n *= s;
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
