/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_menu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:25:04 by jaiane            #+#    #+#             */
/*   Updated: 2025/04/13 10:39:56 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	display_menu(t_data *data)
{
	char	*menu;
	int		y_margin;

	y_margin = 30;
	menu = "------- [FDF] Menu -------";
	mlx_string_put(data->mlx.connection, data->mlx.window, X_MARGIN, y_margin,
		0x03fc35, menu);
	axes_menu(data, &y_margin);
	instructions(data);
}
