/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:43:15 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 11:43:19 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_tokens(int fd)
{
	char	*line;
	char	**split;
	int		tokens;

	tokens = 0;
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	tokens = count_elements(split);
	free(line);
	free_split(split);
	free_static_buffer();
	return (tokens);
}

int	count_lines(int fd)
{
	char	*line;
	int		lines;

	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}
