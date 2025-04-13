/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 11:42:15 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 11:42:17 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	fill_matrix_row(int *value_line, int *color_line, char *line)
		// fill both matrixes (value and color)
{
	char	**row_values;
	char	**values;
	int		i;

	row_values = ft_split(line, ' ');
	i = 0;
	while (row_values[i])
	{
		if (ft_strchr(row_values[i], ','))
		{
			values = ft_split(row_values[i], ',');
			value_line[i] = ft_atoi(values[0]);
			color_line[i] = color_number(values[1]);
			free_split(values);
		}
		else
		{
			value_line[i] = ft_atoi(row_values[i]);
			color_line[i] = 0xffffff;
		}
		i++;
	}
	value_line[i] = 0;
	color_line[i] = 0;
	free_split(row_values);
}

int	**empty_matrix(t_fdf *data)
{
	int	**matrix;
	int	i;

	matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < data->height)
	{
		matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
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

void	fill_matrix(t_fdf *data, int fd)
{
	int		i;
	char	*line;

	data->z_value_m = empty_matrix(data);
	data->z_color_m = empty_matrix(data);
	if (!data->z_value_m || !data->z_color_m)
	{
		free_matrix(data->z_value_m, data->height);
		free_matrix(data->z_color_m, data->height);
		return ;
	}
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix_row(data->z_value_m[i], data->z_color_m[i], line);
		free(line);
		i++;
	}
	free_static_buffer();
}

t_fdf	fdf_data(char *filepath)
{
	int		fd;
	t_fdf	data;

	fd = opened_fd(filepath);
	data.width = count_tokens(fd);
	close(fd);
	fd = opened_fd(filepath);
	data.height = count_lines(fd);
	close(fd);
	fd = opened_fd(filepath);
	fill_matrix(&data, fd);
	close(fd);
	return (data);
}
