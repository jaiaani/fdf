/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:53:08 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 18:53:12 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert letter to uppercase

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_isalpha(c) && c > 96)
		return (c - 32);
	return (c);
}
