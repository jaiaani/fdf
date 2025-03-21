/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:07:27 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:51:21 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Locate a substring in a string					      *	
 * Locates the first occurence of the null-terminated string little in the     *
 * string big, where not more than len characters are searched. 	      *
 * Characters that appear after a \0 character are not searched 	      */

#include "libft.h" 

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;

	i = 0;
	b = (char *)big;
	if (little[0] == '\0')
		return (b);
	while (i < len && big[i])
	{
		j = 0;
		while (little[j] && (i + j) < len && big[i + j] == little[j])
			j++;
		if (!little[j])
			return (b + i);
		i++;
	}
	return (NULL);
}
