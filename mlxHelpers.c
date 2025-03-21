/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxHelpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:09:20 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/13 20:11:12 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void    set_background_color(t_data *data, int color)
{
        int     x;
        int     y;

        y = 0;
        while (y < WIN_HEIGHT)
        {
                x = 0;
                while (x < WIN_WIDTH)
                {
                        mlx_pixel_put(data->mlx.connection, data->mlx.window, x, y, color);
                        x++;
                }
                y++;
        }
}

int	esc_event_handle(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        mlx_destroy_window(data->mlx.connection, data->mlx.window);
        mlx_destroy_display(data->mlx.connection);
        free(data->mlx.connection);
        free_matrix(data->fdf.z_value_m, data->fdf.height);
	free_matrix(data->fdf.z_color_m, data->fdf.height);
        exit(1);
    }
    if (keysym == XK_c)
        set_background_color(data, 0xffffff);
    if (keysym == XK_m)
        draw(data);
    return (0);
}