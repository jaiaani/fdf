/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:58:37 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 18:31:20 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks wheter c is a 7-bit unsigned char value that fits into ASCII        *
 * character set.							      */

#include "libft.h"

int	ft_isascii(unsigned char c)
{
	if (c <= 127)
		return (1);
	return (0);
}
