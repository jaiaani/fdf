/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:42:18 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/02 21:54:12 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)


void	bresenham(t_dot dot, float x1, float y1, t_mlx *mlx)
{
	float	x_step;
	float	y_step;
	float	max;
	
	x_step = x1 - dot.x;
	y_step = y1 - dot.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dot.x - x1) || (int)(dot.y - y1))
	{
		mlx_pixel_put(mlx->connection, mlx->window, dot.x, dot.y, dot.color);
		//my_mlx_pixel_put(data, dot.x, dot.y, dot.color);
		dot.x += x_step;
		dot.y += y_step;
	}
}

void	draw_point(t_dot dot, float x1, float y1, t_data *data)
{
	apply_params_to_point(&dot, &x1, &y1, data);
	//bresenham(dot, x1, y1, data);
	bresenham(dot, x1, y1, &data->mlx);
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	display_menu(data);
	//data->img.ptr = mlx_new_image(data->mlx.connection, WIN_WIDTH, WIN_HEIGHT);
	//data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp, &data->img.line_len, &data->img.endian);
	y = 0;
	while (y < data->fdf.height)
	{
		x = 0;
		while (x < data->fdf.width)
		{
			if (x < data->fdf.width - 1)
				draw_point((t_dot) {x, y, 0, 0}, x + 1, y, data);
			if (y < data->fdf.height - 1)
				draw_point((t_dot) {x, y, 0, 0}, x, y + 1, data);
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(data->mlx.connection, data->mlx.window, data->img.ptr, 0, 0);
}
