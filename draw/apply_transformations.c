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

#include "../fdf.h"

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

void	apply_params_to_points(t_dot *dot, float *x1, float *y1, t_data *data)
{
	float	z1;

	dot->z = data->fdf.matrix[(int)dot->y][(int)dot->x].value;
	z1 = data->fdf.matrix[(int)*y1][(int)*x1].value;
	dot->color = data->fdf.matrix[(int)dot->y][(int)dot->x].color;
	apply_scale_factor(&dot->x, &dot->y, &dot->z, data->params);
	apply_scale_factor(x1, y1, &z1, data->params);
	apply_rotation(&dot->x, &dot->y, &dot->z, data->params);
	apply_rotation(x1, y1, &z1, data->params);
	apply_translation(&dot->x, &dot->y, &dot->z, data->params);
	apply_translation(x1, y1, &z1, data->params);
	isometric(&dot->x, &dot->y, dot->z);
	isometric(x1, y1, z1);
	dot->x += (WIN_W / 2) - data->fdf.center_x;
	dot->y += (WIN_H / 2) - data->fdf.center_y;
	*x1 += (WIN_W / 2) - data->fdf.center_x;
	*y1 += (WIN_H / 2) - data->fdf.center_y;
}
