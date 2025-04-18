/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:49:34 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 11:24:04 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	basic_instructions(t_data *data, int *y_margin)
{
	char	*menu;

	menu = "| - - - - - Instructions - - - - - - - - - - |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'ESC' - exit the program                   |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'i' - zoom in                              |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'd' - zoom out                             |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'r' - reset the object                     |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}

void	rotation_instructions(t_data *data, int *y_margin)
{
	char	*menu;

	*y_margin += 15;
	menu = "| '1 and 2' - rotate on x-axis               |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| '3 and 4' - rotate on y-axis               |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| '5 and 6' - rotate on z-axis               |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}

void	translation_instructions(t_data *data, int *y_margin)
{
	char	*menu;

	*y_margin += 15;
	menu = "| 'Left, Right'        - translate on x-axis |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'Up, Down'           - translate on y-axis |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'Page Up, Page Down' - translate on z-axis |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}

void	scaling_instructions(t_data *data, int *y_margin)
{
	char	*menu;

	*y_margin += 15;
	menu = "| 'w' - increase x-axis scaling factor       |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'q' - decrease x-axis scaling factor       |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 's' - increase y-axis scaling factor       |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
	*y_margin += 15;
	menu = "| 'a' - decrease y-axis scaling factor       |";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, *y_margin,
		0x03fc35, menu);
}

void	instructions(t_data *data)
{
	int	y_margin;

	y_margin = 250;
	basic_instructions(data, &y_margin);
	rotation_instructions(data, &y_margin);
	translation_instructions(data, &y_margin);
	scaling_instructions(data, &y_margin);
}
