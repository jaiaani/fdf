/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:42:18 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/13 21:21:48 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAX(a, b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_mlx_data *data, fdf input)
{
	float	x_step;
	float	y_step;
	float	max;
	int	zoom;
	int	color;
	int	z;
	int z1;

	z = input.z_value_m[(int)y][(int)x];
	z1 = input.z_value_m[(int)y1][(int)x1];
	
	zoom = 10;
	x *= zoom;
	x1 *= zoom;
	y *= zoom;
	y1 *= zoom;
	z *= zoom;
	z1 *= zoom;
	color = input.z_color_m[(int)y][(int)x];
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += 500;
	y += 500;
	x1 += 500;
	y1 += 500;
	x_step = x1 - x;
	y_step = y1 - y;
	
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		x += x_step;
		y += y_step;
	}

}

void	draw(t_mlx_data *data, fdf *input)
{
	int	x;
	int	y;

	y = 0;
	while (y < input->height)
	{
		x = 0;
		while (x < input->width)
		{
			if (x < input->width - 1)
				bresenham(x, y, x + 1, y, data, *input);
			if (y < input->height - 1)
				bresenham(x, y, x, y + 1, data, *input);
			x++;
		}
		y++;
	}
}
