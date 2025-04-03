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

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	apply_scale_factor(t_dot *dot, float *x1, float *y1, int *z1)
{
	dot->x *= dot->sf_x;
	*x1 *= dot->sf_x;
	dot->y *= dot->sf_y;
	*y1 *= dot->sf_y;
	dot->z *= dot->sf_z;
	*z1 *= dot->sf_z;
}

void	apply_translation(t_dot *dot, float *x1, float *y1, int *z1)
{
	dot->x += dot->tf_x;
	*x1 += dot->tf_x;
	dot->y += dot->tf_y;
	*y1 += dot->tf_y;
	dot->z += dot->tf_z;
	*z1 += dot->tf_z;
}

void	apply_params(t_dot *dot, float *x1, float *y1, int *z1)
{
	
	apply_scale_factor(dot, x1, y1, z1);
	apply_translation(dot, x1, y1, z1);
	isometric(&dot->x, &dot->y, dot->z);
	isometric(x1, y1, *z1);
	dot->x += (WIN_WIDTH / 2);
	dot->y += (WIN_HEIGHT / 2);
	*x1 += (WIN_WIDTH / 2);
	*y1 += (WIN_HEIGHT / 2);
}


void	bresenham(t_dot dot, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int z1;

	dot.z = data->fdf.z_value_m[(int)dot.y][(int)dot.x];
	z1 = data->fdf.z_value_m[(int)y1][(int)x1];

        if ((dot.y >= 0 && dot.y < data->fdf.height) && (dot.x >= 0 && dot.x < data->fdf.width))
                dot.color = data->fdf.z_color_m[(int)dot.y][(int)dot.x];
	
	apply_params(&dot, &x1, &y1, &z1);
	x_step = x1 - dot.x;
	y_step = y1 - dot.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dot.x - x1) || (int)(dot.y - y1))
	{
		mlx_pixel_put(data->mlx.connection, data->mlx.window, dot.x, dot.y, dot.color);
		dot.x += x_step;
		dot.y += y_step;
	}

}

/*void	bresenham(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	float	max;
	int	zoom;
	int	color;
	int	z;
	int z1;

	z = data->fdf.z_value_m[(int)y][(int)x];
	z1 = data->fdf.z_value_m[(int)y1][(int)x1];

        if ((y >= 0 && y < data->fdf.height) && (x >= 0 && x < data->fdf.width))
                color = data->fdf.z_color_m[(int)y][(int)x];
	else
   		color = 0x00FF00;
	
	zoom = 2;
	x *= zoom;
	x1 *= zoom;
	y *= zoom;
	y1 *= zoom;
	z *= zoom;
	z1 *= zoom;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += (WIN_WIDTH/2);
	y += (WIN_HEIGHT/2);
	x1 += (WIN_WIDTH/2);
	y1 += (WIN_HEIGHT/2);
	x_step = x1 - x;
	y_step = y1 - y;
	
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx.connection, data->mlx.window, x, y, color);
		x += x_step;
		y += y_step;
	}

}*/

/*void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->fdf.height)
	{
		x = 0;
		while (x < data->fdf.width)
		{
			if (x < data->fdf.width - 1)
				bresenham(x, y, x + 1, y, &data->mlx, data->fdf);
			if (y < data->fdf.height - 1)
				bresenham(x, y, x, y + 1, &data->mlx, data->fdf);
			x++;
		}
		y++;
	}
}*/

/*void	draw_new(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	display_menu(data);
	while (y < data->fdf.height)
	{
		x = 0;
		while (x < data->fdf.width)
		{
			if (x < data->fdf.width - 1)
				bresenham(x, y, x + 1, y, data);
			if (y < data->fdf.height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}*/

void	init_dot(t_dot *dot)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
	dot->color = 0xffffff;
	dot->zoom = 8;
	dot->sf_x = dot->zoom;
	dot->sf_y = dot->zoom;
	dot->sf_z = dot->zoom;
	dot->tf_x = 0;
	dot->tf_y = 0;
	dot->tf_z = 0;
	dot->angle = 0;
}

void	draw(t_data *data)
{
	while (data->dot.y < data->fdf.height)
	{
		data->dot.x = 0;
		while (data->dot.x < data->fdf.width)
		{
			if (data->dot.x < data->fdf.width - 1)
				bresenham(data->dot, data->dot.x + 1, data->dot.y, data);
			if (data->dot.y < data->fdf.height - 1)
				bresenham(data->dot, data->dot.x, data->dot.y + 1, data);
			data->dot.x++;
		}
		data->dot.y++;
	}
}

void	draw_initial_map(t_data *data)
{
	t_dot 	dot;

	init_dot(&dot);
	data->dot = dot;
	display_menu(data);
	draw(data);
}