/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:04:21 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/18 23:05:37 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

void window_session(t_mlx_data *mlx, fdf *data)
{
	draw(mlx, data);
	mlx_key_hook(mlx->win_ptr, handle_events, data);
	mlx_loop(mlx->mlx_ptr);
}


void initialize_mlx(t_mlx_data *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1980, 1980, "FDF!");
	if (!mlx->win_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	//t_mlx_data	mlx;
	fdf			data;

	if (argc != 2)
		return (1);

	data = fdf_data(argv[1]);
	for (int i = 0; i < data.height; i++)
	{
		for (int j = 0; j < data.width; j++)
		{
			printf("%d ", data.z_color_m[i][j]);
		}
		printf("\n");
	}
	/*initialize_mlx(&mlx);
	window_session(&mlx, &data);
	free_matrix(data.z_value_m, data.height);
	free_matrix(data.z_color_m, data.height);*/
	
	return (0);
}
