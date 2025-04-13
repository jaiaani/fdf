/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_transformations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:57:17 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/10 23:58:51 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	apply_params_to_point(t_dot *dot, float *x1, float *y1, t_data *data)
{
	float	z1;

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
	dot->x += (WIN_W / 2);
	dot->y += (WIN_H / 2);
	*x1 += (WIN_W / 2);
	*y1 += (WIN_H / 2);
}
