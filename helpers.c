#include "fdf.h"

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

int	color_number(char *hex_str)
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