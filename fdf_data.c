#include "fdf.h"

// ----- helpers -----

int	opened_fd(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		perror("Error\n");
		exit(1);
	}
	return (fd);
}

int	count_elements(char **z_input)
{
	int	i;

	i = 0;
	while (z_input[i])
		i++;
	return (i);
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

void	free_split(char **split)
{
    int	i;

    if (!split)
        return;
    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
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
// ----------------------

int count_tokens(int fd)
{
    char	*line;
    int		tokens;
    char    **split;

    tokens = 0;
    line = get_next_line(fd);
    split = ft_split(line, ' ');
    tokens = count_elements(split);
    free(line);
    free_split(split);
    free_static_buffer();
    return (tokens);
}

int count_lines(int fd)
{
    char *line;
    int lines;

    lines = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        free(line);
        lines++;
    }
    close(fd);
    return (lines);
}

void fill_matrix_row(int *value_line, int *color_line, char *line) // fill both matrixes (value and color)
{
    char **row_values;
    char **values;
    int i;

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
            color_line[i] =  0xffffff;
        }
        i++;
    }
    value_line[i] = 0;
    color_line[i] = 0;
    free_split(row_values);
}

int **empty_matrix(t_fdf *data)
{
    int **matrix;
    int i;
    
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

void fill_matrix(t_fdf *data, int fd)
{
    int i;
    char *line;

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


t_fdf fdf_data(char *filepath)
{
    int	fd;
    t_fdf data;

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