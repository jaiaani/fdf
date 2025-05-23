/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:04:21 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/18 14:37:10 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <unistd.h>

void	initialize_data(t_data *data)
{
	data->params.zoom = 5;
	data->params.sf_x = 0;
	data->params.sf_y = 0;
	data->params.sf_z = 0;
	data->params.tf_x = 0;
	data->params.tf_y = 0;
	data->params.tf_z = 0;
	data->params.x_angle = 0.0;
	data->params.y_angle = 0.0;
	data->params.z_angle = 0.0;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (1);
	data.fdf = fdf_data(argv[1]);
	data.mlx.connection = mlx_init();
	if (data.mlx.connection == NULL)
		return (1);
	data.mlx.window = mlx_new_window(data.mlx.connection, WIN_W, WIN_H, "-");
	if (data.mlx.window == NULL)
	{
		mlx_destroy_display(data.mlx.connection);
		free(data.mlx.connection);
		return (1);
	}
	initialize_data(&data);
	draw(&data);
	mlx_key_hook(data.mlx.window, event_handler, &data.mlx);
	mlx_hook(data.mlx.window, 17, 0, close_window, &data);
	// mlx_hook(data.mlx.window, 2, 1L<<15, draw, &data);
	mlx_loop(data.mlx.connection);
	free_matrix(data.fdf.matrix, data.fdf.height);
	return (0);
}
