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

typedef struct s_data
{
        t_mlx      mlx;
        t_fdf           fdf;
}               t_data;


int     handle_events(int keysym, t_mlx *data);
void    bresenham(float x, float y, float x1, float y1, t_mlx *data, t_fdf input);
void    draw(t_data *data);
void	free_matrix(int **matrix, int height);
t_fdf 	fdf_data(char *filepath);
int	esc_event_handle(int keysym, t_data *data);

#endif
