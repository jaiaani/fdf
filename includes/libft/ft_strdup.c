/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:27:17 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:42:49 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Duplicate a string							      *	
 * Returns a pointer to a new string which is a duplicate of the string s.    *
 * Memory for the new string is obtained with malloc(), and can be freed with *
 * free 								      */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (*s)
		dup[i++] = *s++;
	dup[i] = '\0';
	return (dup);
}
