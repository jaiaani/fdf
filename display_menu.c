#include "fdf.h"


void    axis_menu(t_data *data)
{
    char *menu;


    menu = "| - - - - - x-axis - - - - --|";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 50, 0x03fc35, menu);
    menu = "|scaling-factor:";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 70, 0x03fc35, menu);
    menu = ft_strjoin("                 ", ft_itoa(data->params.sf_x));
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 70, 0x03fc35, menu);
    menu = "                             |";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 70, 0x03fc35, menu);
    menu = "|translation-factor:";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 90, 0x03fc35, menu);
    menu = ft_strjoin("                    ", ft_itoa(data->params.tf_x));

}

void    display_menu(t_data *data)
{
    char *menu;

    menu = "------- [FDF] Menu -------";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 30, 0x03fc35, menu);
    axis_menu(data);
    
}