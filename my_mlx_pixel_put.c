/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:00:58 by jaiane            #+#    #+#             */
/*   Updated: 2025/03/13 20:15:24 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*d;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		d = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
		*(unsigned int*)d = color;
	}
	
}

