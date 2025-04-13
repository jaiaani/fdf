/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:11:00 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 18:11:03 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	**empty_matrix(t_fdf *fdf)
{
	t_point	**matrix;
	int		i;

	matrix = (t_point **)malloc(sizeof(t_point *) * (fdf->height + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < fdf->height)
	{
		matrix[i] = (t_point *)malloc(sizeof(t_point *) * fdf->width + 1);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

void	parse_point(t_point *row, char *str, int i)
{
	char	**values;

	if (ft_strchr(str, ','))
	{
		values = ft_split(str, ',');
		if (!values)
		{
			free(str);
			return ;
		}
		row[i].value = fast_atoi(values[0]);
		row[i].color = color_number(values[1]);
		free_split(values);
	}
	else
	{
		row[i].value = fast_atoi(str);
		row[i].color = 0xffffff;
	}
}

void	fill_matrix_row(t_point *row, char *line)
{
	char	**row_values;
	int		i;

	row_values = ft_split(line, ' ');
	if (!row_values)
		return ;
	i = 0;
	while (row_values[i])
	{
		parse_point(row, row_values[i], i);
		i++;
	}
	free_split(row_values);
}

void	fill_matrix(t_fdf *fdf, int fd)
{
	int		i;
	char	*line;

	fdf->matrix = empty_matrix(fdf);
	if (!fdf->matrix)
		return ;
	i = 0;
	while (i < fdf->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		fill_matrix_row(fdf->matrix[i], line);
		free(line);
		i++;
	}
	free_static_buffer();
}

t_fdf	fdf_data(char *filepath)
{
	int		fd;
	t_fdf	fdf;

	fd = opened_fd(filepath);
	fdf_init(&fdf, fd);
	close(fd);
	fd = opened_fd(filepath);
	fill_matrix(&fdf, fd);
	close(fd);
	return (fdf);
}
