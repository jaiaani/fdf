/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 07:57:50 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/18 21:23:45 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count_tokens(char *s)
{
	int	tokens;
	int	inside_token;

	tokens = 0;
	if (!s)
		return (0);
	while (*s)
	{
		inside_token = 0;
		while (*s == ' ' && *s)
			++s;
		while (*s != ' ' && *s)
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

int	count_lines(int fd)
{
	char	*line;
	int		lines;
	int		ret;

	lines = -1;
	while (1)
	{
		line = get_next_line(fd);
		free(line);
		lines++;
		if (!line)
		{
			free(line);
			break;
		}
	}
	close(fd);
	return (lines);
}

int	count_elements(char **z_input)
{
	int	i;

	i = 0;
	while (z_input[i])
		i++;
	return (i);
}

int	color_number(const char *hex_str)
{
	int	color;
	if (!hex_str || *hex_str != '0' || *(hex_str + 1) != 'x')
		return (0);
	color = 0;
	hex_str += 2;
	while (*hex_str)
	{
		color *= 16;
		if (*hex_str >= '0' && *hex_str <= '9')
			color += *hex_str - '0';
		else if (*hex_str >= 'a' && *hex_str <= 'f')
			color += *hex_str - 'a' + 10;
		else if (*hex_str >= 'A' && *hex_str <= 'F')
			color += *hex_str - 'A' + 10;
		else
			return (0);
		hex_str++;
	}
	return (color);
}

void	free_matrix(int **matrix, int height)
{
	int	i;

	if (!matrix)
		return;
	i = 0;
	while (i < height)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void fill_matrix_row(int *z_line, char *line)
{
	char **nums;
	int i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		i++;
	}
	z_line[i] = 0;
	free(nums);
}

int	**z_matrix(int fd, int width, int height)
{
	int	**matrix;
	int	i;
	char	*line;

	matrix = (int **)malloc(sizeof(int *) * (height + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrix[i] = (int *)malloc(sizeof(int) * (width + 1));
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		fill_matrix_row(matrix[i], line);
		free(line);
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc == 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	
	int i = 0;
	int j = 0;
	int	**z;
	int k = 0;

	z = z_matrix(fd, 20, 20);
	while (i <= 19)
	{
		j = 0;
		while (j <= 19)
		{
			printf("%3d ", z[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	free_matrix(z, 20);
	free_static_buffer();
	close(fd);

}
