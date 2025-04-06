/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:04:21 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/18 23:05:37 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <stdio.h>

int     menu(t_data *data)
{
        mlx_string_put(data->mlx.connection, data->mlx.window, 150, 150, 0xffffff, "Menu");
        return (0);
}


int	main(int argc, char *argv[])
{
        t_data  data;
        
        if (argc != 2)
               return (1);
        data.fdf = fdf_data(argv[1]);
        data.mlx.connection = mlx_init();
        if (data.mlx.connection == NULL)
                return (1);
        data.mlx.window = mlx_new_window(data.mlx.connection, WIN_WIDTH, WIN_HEIGHT, "My first window!");
        if (data.mlx.window == NULL)
        {
                mlx_destroy_display(data.mlx.connection);
                free(data.mlx.connection);
                return (1);
        }
        // data.img.ptr = mlx_new_image(data.mlx.connection, WIN_WIDTH, WIN_HEIGHT);
        //data.img.addr = mlx_get_data_addr(data.img.ptr, &data.img.bpp, &data.img.line_len, &data.img.endian);
        draw_initial_map(&data);
        mlx_key_hook(data.mlx.window, esc_event_handle, &data.mlx);
        mlx_loop(data.mlx.connection); 
        free_matrix(data.fdf.z_value_m, data.fdf.height);
	free_matrix(data.fdf.z_color_m, data.fdf.height);
        return (0);
}
