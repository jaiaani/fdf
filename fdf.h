/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 19:38:42 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 11:34:25 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libs/get_next_line/get_next_line.h"
# include "libs/libft/libft.h"
# include "libs/minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_W 1920
# define WIN_H 1080
# define X_MARGIN 10

typedef struct s_mlx_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_mlx_data
{
	void		*connection;
	void		*window;
}				t_mlx;

typedef struct s_fdf_data
{
	int			width;
	int			height;
	int			**z_value_m;
	int			**z_color_m;
}				t_fdf;

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_dot;

typedef struct s_params
{
	int			zoom;
	int			sf_x;
	int			sf_y;
	int			sf_z;
	int			tf_x;
	int			tf_y;
	int			tf_z;
	float		x_angle;
	float		y_angle;
	float		z_angle;
}				t_params;

typedef struct s_data
{
	t_mlx		mlx;
	t_fdf		fdf;
	t_img		img;
	t_dot		dot;
	t_params	params;
}				t_data;

int				opened_fd(char *filepath);
int				count_elements(char **z_input);
int				color_number(char *hex_str);
int				event_handler(int keysym, t_data *data);
int				count_tokens(int fd);
int				count_lines(int fd);

void			apply_rotation(float *x, float *y, float *z, t_params params);
void			apply_params_to_point(t_dot *dot, float *x1, float *y1,
					t_data *data);
void			free_matrix(int **matrix, int height);
void			free_split(char **split);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			display_menu(t_data *data);
void			draw(t_data *data);

void			mlx_put_dynamic_line(t_data *data, int *y_margin, char *prefix,
					int value);
void			scaling_factor(t_data *data, int *y_margin, int sf);
void			translation_factor(t_data *data, int *y_margin, int tf);
void			rotation_angle(t_data *data, int *y_margin, int angle);
void			axes_menu(t_data *data, int *y_margin);
void			instructions(t_data *data);

void			zoom(int keysym, t_data *data);
void			scale(int keysym, t_data *data);
void			rotate(int keysym, t_data *data);
void			translate(int keysym, t_data *data);
void			reset(int keysym, t_data *data);
int			close_window(t_data *data);


t_fdf			fdf_data(char *filepath);
#endif
