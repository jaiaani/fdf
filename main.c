/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:04:21 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/14 07:49:20 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>

int	main(void)
{
	t_mlx_data	data;
	t_img_data	img;
	fdf	input;
	int	height;
	int	width;


	width = 20;
	height = 10;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 800, "FDF!");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	draw(&data, width, height);
	mlx_key_hook(data.win_ptr, handle_events, &data);
	mlx_loop(data.mlx_ptr);
}
