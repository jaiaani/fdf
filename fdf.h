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

#include "minilibx-linux/mlx.h"
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <math.h>
#include <X11/keysym.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_tmlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}		t_mlx_data;

typedef struct s_img_data
{
	void	*img;
	char	*addr;
	int	bpp;
	int	line_len;
	int	endian;
}		t_img_data;

typedef	struct s_fdf
{
	int	width;
	int	height;
}		fdf;

void	my_mlx_pixel_put(t_img_data *img, int x, int y, int color);
int     handle_events(int keysym, t_mlx_data *data);
void    bresenham(float x, float y, float x1, float y1, t_mlx_data *data);
void    draw(t_mlx_data *data, int width, int height);

#endif
