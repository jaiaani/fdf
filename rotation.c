/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:04:09 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/11 00:05:31 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_x_rotation(float *y, float *z, t_params params)
{
	float	angle_rad;
	float	y_temp;
	float	z_temp;

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
	float	angle_rad;
	float	x_temp;
	float	z_temp;

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
	float	angle_rad;
	float	x_temp;
	float	y_temp;

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
