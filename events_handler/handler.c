/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 13:19:56 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 13:19:58 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	event_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_window(data);
	zoom(keysym, data);
	scale(keysym, data);
	rotate(keysym, data);
	translate(keysym, data);
	reset(keysym, data);
	mlx_clear_window(data->mlx.connection, data->mlx.window);
	draw(data);
	return (0);
}
