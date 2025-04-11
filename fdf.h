/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:38:42 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/18 19:14:09 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libs/minilibx-linux/mlx.h"
#include "libs/get_next_line/get_next_line.h"
#include "libs/libft/libft.h" 
#include <stdio.h>
#include <math.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <fcntl.h>

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

typedef struct s_mlx_img
{
        void    *ptr;
        char    *addr;
        int     bpp;
        int     endian;
        int     line_len;
}               t_img;

typedef struct s_mlx_data
{
	void	*connection;
	void	*window;
}		t_mlx;


typedef	struct s_fdf_data
{
	int	width;
	int	height;
	int **z_value_m;
	int **z_color_m;
}		t_fdf;

typedef struct s_dot
{
        float		x;
        float		y;
        float		z;
        int		color;
}		t_dot;

typedef struct s_params
{
        int     zoom;
        int     sf_x;
        int     sf_y;
        int     sf_z;
        int     tf_x;
        int     tf_y;
        int     tf_z;
        float     x_angle;
        float     y_angle;
        float     z_angle;
}               t_params;

typedef struct s_data
{
        t_mlx      mlx;
        t_fdf      fdf;
        t_img      img;
        t_dot      dot;
        t_params   params;
}               t_data;


int	opened_fd(char *filepath);
int	count_elements(char **z_input);
int	color_number(char *hex_str);
int	event_handler(int keysym, t_data *data);

void	free_matrix(int **matrix, int height);
void	free_split(char **split);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    display_menu(t_data *data);
void    draw(t_data *data);

t_fdf 	fdf_data(char *filepath);
#endif
