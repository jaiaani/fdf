/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:42:18 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 11:32:45 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	mod_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	max_num(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	bresenham(t_dot dot, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;

	x_step = x1 - dot.x;
	y_step = y1 - dot.y;
	max = max_num(mod_abs(x_step), mod_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dot.x - x1) || (int)(dot.y - y1))
	{
		my_mlx_pixel_put(data, dot.x, dot.y, dot.color);
		dot.x += x_step;
		dot.y += y_step;
	}
}

void	draw_line(t_dot dot, float x1, float y1, t_data *data)
{
	apply_params_to_points(&dot, &x1, &y1, data);
	bresenham(dot, x1, y1, data);
}

int	draw(t_data *data)
{
	int	x;
	int	y;

	data->img.ptr = mlx_new_image(data->mlx.connection, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	y = 0;
	while (y < data->fdf.height)
	{
		x = 0;
		while (x < data->fdf.width)
		{
			if (x < data->fdf.width - 1)
				draw_line((t_dot){x, y, 0, 0}, x + 1, y, data);
			if (y < data->fdf.height - 1)
				draw_line((t_dot){x, y, 0, 0}, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.connection, data->mlx.window,
		data->img.ptr, 0, 0);
	display_menu(data);
	return (0);
}
