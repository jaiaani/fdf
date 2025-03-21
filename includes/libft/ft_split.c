/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:47:47 by jados-sa          #+#    #+#             */
/*   Updated: 2024/10/29 19:30:26 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates with malloc() and returns an array of strings obtained by 	      *
 * splitting 's' using the character as a delimiter. The array must end       *
 * with a NULL pointer.    						      *
 * Parameters: 								      *
 * s: the string to be slipt						      *
 * c: the delimiter character. 						      */

#include "libft.h" 

static size_t	count_tokens(char const *s, char c)
{
	int		tokens;
	int		inside_token;

	tokens = 1;
	if (!s)
		return (0);
	while (*s)
	{
		inside_token = 0;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			if (!inside_token)
			{
				++tokens;
				inside_token = 1;
			}
			++s;
		}
	}
	return (tokens);
}

static size_t	token_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len + 1);
}

static char	**insert_token(size_t *i, char **list, char const *s, char c)
{
	list[*i] = (char *)malloc(token_len(s, c) * sizeof(char));
	if (!list[*i])
	{
		while (*i)
			free(list[*i--]);
		free(list);
		return (NULL);
	}
	ft_strlcpy(list[*i], s, token_len(s, c));
	*i += 1;
	return (list);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	i;
	int		inside_token;

	strs = (char **) malloc (count_tokens(s, c) * sizeof (char *));
	if (!s || !strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		inside_token = 0;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			if (!inside_token)
			{
				insert_token(&i, strs, s, c);
				inside_token = 1;
			}
			++s;
		}
	}
	strs[i] = 0;
	return (strs);
}
