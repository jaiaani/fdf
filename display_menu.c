#include "fdf.h"

void    display_menu(t_data *data)
{
    char *menu;

    menu = "up, down, left, right: move";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 20, 0x03fc35, menu);
    menu = "c: change color";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 35, 0x03fc35, menu);
    menu = "f: full screen mode";
    mlx_string_put(data->mlx.connection, data->mlx.window, 10, 50, 0x03fc35, menu);
}