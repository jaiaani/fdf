/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:26:07 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 11:23:20 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	mlx_put_dynamic_line(t_data *data, int *y, char *prefix, int value)
{
	char	*itoa_tmp;
	char	*line;

	itoa_tmp = ft_itoa(value);
	line = ft_strjoin(prefix, itoa_tmp);
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y,
		0x03fc35, line);
	free(itoa_tmp);
	free(line);
}

void	scaling_factor(t_data *data, int *y_margin, int sf)
{
	char	*menu;

	*y_margin += 15;
	menu = "|scaling-factor:";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	mlx_put_dynamic_line(data, y_margin, "                     ", sf);
	menu = "                             |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}

void	translation_factor(t_data *data, int *y_margin, int tf)
{
	char	*menu;

	*y_margin += 15;
	menu = "|translation-factor:";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	mlx_put_dynamic_line(data, y_margin, "                     ", tf);
	menu = "                             |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}

void	rotation_angle(t_data *data, int *y_margin, int angle)
{
	char	*menu;

	*y_margin += 15;
	menu = "|rotation-angle:";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	mlx_put_dynamic_line(data, y_margin, "                     ", angle);
	menu = "                             |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}
