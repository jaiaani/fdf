/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:19:56 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/18 14:40:11 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	event_handler(int keysym, t_data *data)
{
	int	redraw;

	redraw = 0;
	if (keysym == XK_Escape)
		close_window(data);
	zoom(keysym, data, &redraw);
	scale(keysym, data, &redraw);
	rotate(keysym, data, &redraw);
	translate(keysym, data, &redraw);
	reset(keysym, data, &redraw);
	if (redraw)
	{
		mlx_destroy_image(data->mlx.connection, data->img.ptr);
		mlx_clear_window(data->mlx.connection, data->mlx.window);
		draw(data);
	}
	return (0);
}
