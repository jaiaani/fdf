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

void	isometric(float *x, float *y, float z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	apply_scale_factor(float *x, float *y, float *z, t_params params)
{
	*x *= params.sf_x + params.zoom;
	*y *= params.sf_y + params.zoom;
	*z *= params.sf_z + params.zoom;
}

void	apply_translation(float *x, float *y, float *z, t_params params)
{
	*x += params.tf_x;
	*y += params.tf_y;
	*z += params.tf_z;
}

void	apply_x_rotation(float *y, float *z, t_params params)
{
	float angle_rad;
	float y_temp;
	float z_temp;

	if (params.x_angle == 0)
		return ;
	angle_rad = params.x_angle * (M_PI / 180);
	y_temp = *y;
	z_temp = *z;
	*y = y_temp * cos(angle_rad) - z_temp * sin(angle_rad);
	*z = y_temp * sin(angle_rad) + z_temp * cos(angle_rad);
}

void	apply_y_rotation(float *x, float *z, t_params params)
{
	float angle_rad;
	float x_temp;
	float z_temp;

	if (params.y_angle == 0)
		return ;
	angle_rad = params.y_angle * (M_PI / 180);
	x_temp = *x;
	z_temp = *z;
	*x = x_temp * cos(angle_rad) + z_temp * sin(angle_rad);
	*z = -x_temp * sin(angle_rad) + z_temp * cos(angle_rad);
}

void	apply_z_rotation(float *x, float *y, t_params params)
{
	float angle_rad;
	float x_temp;
	float y_temp;

	if (params.z_angle == 0)
		return ;
	angle_rad = params.z_angle * (M_PI / 180);
	x_temp = *x;
	y_temp = *y;
	*x = x_temp * cos(angle_rad) - y_temp * sin(angle_rad);
	*y = x_temp * sin(angle_rad) + y_temp * cos(angle_rad);
}

void	apply_rotation(float *x, float *y, float *z, t_params params)
{
	apply_z_rotation(x, y, params);
	apply_y_rotation(x, z, params);
	apply_x_rotation(y, z, params);

}

void	apply_params_to_point(t_dot *dot, float *x1, float *y1, t_data *data)
{
	float z1;

	dot->z = data->fdf.z_value_m[(int)dot->y][(int)dot->x];
	z1 = data->fdf.z_value_m[(int)*y1][(int)*x1];
	if ((dot->y >= 0 && dot->y < data->fdf.height) && (dot->x >= 0 && dot->x < data->fdf.width))
			dot->color = data->fdf.z_color_m[(int)dot->y][(int)dot->x];
	else
		dot->color = data->dot.color;
	apply_scale_factor(&dot->x, &dot->y, &dot->z, data->params);
	apply_scale_factor(x1, y1, &z1, data->params);
	apply_rotation(&dot->x, &dot->y, &dot->z, data->params);
	apply_rotation(x1, y1, &z1, data->params);
	apply_translation(&dot->x, &dot->y, &dot->z, data->params);
	apply_translation(x1, y1, &z1, data->params);
	isometric(&dot->x, &dot->y, dot->z);
	isometric(x1, y1, z1);
	dot->x += (WIN_WIDTH / 2);
	dot->y += (WIN_HEIGHT / 2);
	*x1 += (WIN_WIDTH / 2);
	*y1 += (WIN_HEIGHT / 2);
}


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
