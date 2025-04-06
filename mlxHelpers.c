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

int esc_event_handle(int keysym, t_data *data)
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
    if (keysym == XK_a)
        {
            data->params.sf_x += 1;
            data->params.sf_y += 1;
            data->params.sf_z += 1;
        }
    if (keysym == XK_d)
        {
            data->params.sf_x -= 1;
            data->params.sf_y -= 1;
            data->params.sf_z -= 1;
        }
    if (keysym == XK_Up)
        data->params.sf_y += 1;
    if (keysym == XK_Down)
        data->params.sf_y -= 1;
    if (keysym == XK_Right)
        data->params.sf_x += 1;
    if (keysym == XK_Left)
        data->params.sf_x -= 1;
    if (keysym == XK_KP_Add)
        data->params.sf_z += 1;
    if (keysym == XK_KP_Subtract)
        data->params.sf_z -= 1;
    if (keysym == XK_r)
        {
            data->params.tf_x += 1;
        }
    if (keysym == XK_l)
        {
            data->params.tf_x -= 1;
        }
    if (keysym == XK_t)
        {
            data->params.tf_y += 1;
        }
    if (keysym == XK_b)
        {
            data->params.tf_y -= 1;
        }
    if (keysym == XK_u)
        {
            data->params.tf_z += 1;
        }
    if (keysym == XK_d)
        {
            data->params.tf_z -= 1;
        }
    if (keysym == XK_c)
        set_background_color(data, 0xff007f);
    if (keysym == XK_m)
        draw_initial_map(data);
    mlx_clear_window(data->mlx.connection, data->mlx.window);
    draw(data);
    printf("zoom: %d, sf_x: %d, sf_y: %d, sf_z: %d\n",data->params.zoom, data->params.sf_x, data->params.sf_y, data->params.sf_z);
    
    return (0);
}

/*int	esc_event_handle(int keysym, t_data *data)
{
   
    if (keysym == XK_c)
        set_background_color(data, 0xff007f);
    if (keysym == XK_m)
        draw_initial_map(data);
    scaling_factor_handler(keysym, data);
    return (0);
}*/