/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:53:29 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 18:53:32 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// convert letter to lowercase

#include "libft.h"

int	ft_tolower(int c)
{
	if (ft_isalpha(c) && c < 91)
		return (c + 32);
	return (c);
}
