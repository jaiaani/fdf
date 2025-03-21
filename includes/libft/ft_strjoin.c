/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 22:05:38 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:25:04 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Allocates (with malloc(3)) and returns a new string, which is the result    *	
 * of the concatenation of 's1' and 's2'.				      *	
 * 	s1: The prefix string.						      *	
 * 	s2: The suffix string.						      *
 * Returns the new string. NULL if the allocaion fails.			      */	

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (total_len + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, ft_strlen(s1) + 1);
	ft_strlcat(join, s2, total_len + 1);
	return (join);
}
