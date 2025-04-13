/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:43:15 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 18:11:41 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fdf_width(t_fdf *fdf, char *line)
{
	int	i;

	i = 0;
	fdf->width = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i])
			fdf->width++;
		while (line[i] && line[i] != ' ')
			i++;
	}
}

void	fdf_init(t_fdf *fdf, int fd)
{
	char	*line;

	fdf->height = 1;
	line = get_next_line(fd);
	if (!line)
		return ;
	fdf_width(fdf, line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		fdf->height++;
	}
}
