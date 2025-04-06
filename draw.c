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

void	apply_scale_factor(t_dot *dot, float *x1, float *y1, int *z1, t_params params)
{
	dot->x *= params.sf_x;
	*x1 *= params.sf_x;
	dot->y *= params.sf_y;
	*y1 *= params.sf_y;
	dot->z *= params.sf_z;
	*z1 *= params.sf_z;
}

void	apply_translation(t_dot *dot, float *x1, float *y1, int *z1, t_params params)
{
	dot->x += params.tf_x;
	*x1 += params.tf_x;
	dot->y += params.tf_y;
	*y1 += params.tf_y;
	dot->z += params.tf_z;
	*z1 += params.tf_z;
}

void	apply_params(t_dot *dot, float *x1, float *y1, int *z1, t_params params)
{
	
	apply_scale_factor(dot, x1, y1, z1, params);
	apply_translation(dot, x1, y1, z1, params);
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
	
	apply_params(&dot, &x1, &y1, &z1, data->params);
	x_step = x1 - dot.x;
	y_step = y1 - dot.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(dot.x - x1) || (int)(dot.y - y1))
	{
		mlx_pixel_put(data->mlx.connection, data->mlx.window, dot.x, dot.y, dot.color);
		//my_mlx_pixel_put(data, dot.x, dot.y, dot.color);
		dot.x += x_step;
		dot.y += y_step;
	}

}

void	init_dot(t_dot *dot)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
	dot->color = 0xffffff;
}

void	init_params(t_params *params)
{
	params->zoom = 8;
	params->sf_x = params->zoom;
	params->sf_y = params->zoom;
	params->sf_z = params->zoom;
	params->tf_x = 0;
	params->tf_y = 0;
	params->tf_z = 0;
	params->angle = 0;
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	display_menu(data);
	y = 0;
	while (y < data->fdf.height)
	{
		x = 0;
		while (x < data->fdf.width)
		{
			if (x < data->fdf.width - 1)
				bresenham((t_dot) {x, y, 0, 0}, x + 1, y, data);
			if (y < data->fdf.height - 1)
				bresenham((t_dot) {x, y, 0, 0}, x, y + 1, data);
			x++;
		}
		y++;
	}
	//mlx_put_image_to_window(data->mlx.connection, data->mlx.window, data->img.ptr, 0, 0);
}

void	draw_initial_map(t_data *data)
{
	t_dot 	dot;
	t_params params;

	init_dot(&dot);
	init_params(&params);
	data->dot = dot;
	data->params = params;

	draw(data);
}