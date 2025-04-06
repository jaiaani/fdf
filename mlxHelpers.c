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

void close_window(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
   {
        mlx_destroy_image(data->mlx.connection, data->img.ptr);
        mlx_destroy_window(data->mlx.connection, data->mlx.window);
        mlx_destroy_display(data->mlx.connection);
        free(data->mlx.connection);
        free_matrix(data->fdf.z_value_m, data->fdf.height);
	    free_matrix(data->fdf.z_color_m, data->fdf.height);
        exit(1);
    }
}

void    zoom_object(int keysym, t_data *data)
{
    if (keysym == XK_i)
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
}

void    scale_object(int keysym, t_data *data)
{
    int scale_step;

    scale_step = 5;
    if (keysym == XK_w)
        data->params.sf_x += scale_step;
    if (keysym == XK_q)
        data->params.sf_x -= scale_step;
    if (keysym == XK_s)
        data->params.sf_y += scale_step;
    if (keysym == XK_a)
        data->params.sf_y -= scale_step;
    if (keysym == XK_x)
        data->params.sf_z += scale_step;
    if (keysym == XK_z)
        data->params.sf_z -= scale_step;
}

void    rotate_object(int keysym, t_data *data)
{
    float angle_step;

    angle_step = 10.0;
    if (keysym == XK_1)
        data->params.x_angle -= angle_step;
    if (keysym == XK_2)
        data->params.x_angle += angle_step;
    if (keysym == XK_3)
        data->params.y_angle -= angle_step;
    if (keysym == XK_4)
        data->params.y_angle += angle_step;
    if (keysym == XK_5)
        data->params.z_angle -= angle_step;
    if (keysym == XK_6)
        data->params.z_angle += angle_step;
}

void  translate_object(int keysym, t_data *data)
{
    int translate_step;

    translate_step = 10;
    if (keysym == XK_Left)
        data->params.tf_x -= translate_step;
    if (keysym == XK_Right)
        data->params.tf_x += translate_step;
    if (keysym == XK_Up)
        data->params.tf_y -= translate_step;
    if (keysym == XK_Down)
        data->params.tf_y += translate_step;
    if (keysym == XK_Page_Up)
        data->params.tf_z -= translate_step;
    if (keysym == XK_Page_Down)
        data->params.tf_z += translate_step;
}

void    reset_object(int keysym, t_data *data)
{
     if (keysym == XK_r)
    {
        data->dot.x = 0;
        data->dot.y = 0;
        data->dot.z = 0;
        data->dot.color = 0xffffff;
        data->params.zoom = 8;
        data->params.sf_x = data->params.zoom;
        data->params.sf_y = data->params.zoom;
        data->params.sf_z = data->params.zoom;
        data->params.tf_x = 0;
        data->params.tf_y = 0;
        data->params.tf_z = 0;
        data->params.x_angle = 0.0;
        data->params.y_angle = 0.0;
        data->params.z_angle = 0.0;
    }
}

int esc_event_handle(int keysym, t_data *data)
{
    close_window(keysym, data);
    zoom_object(keysym, data);
    scale_object(keysym, data);
    rotate_object(keysym, data);
    translate_object(keysym, data);
    reset_object(keysym, data);
    if (keysym == XK_c)
        set_background_color(data, 0xff007f);
    mlx_clear_window(data->mlx.connection, data->mlx.window);
    mlx_destroy_image(data->mlx.connection, data->img.ptr);
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