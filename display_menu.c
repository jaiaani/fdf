#include "fdf.h"

void mlx_put_dynamic_line(t_data *data, int x, int *y, char *prefix, int value)
{
    char *itoa_tmp = ft_itoa(value);
    char *line = ft_strjoin(prefix, itoa_tmp);
    
    mlx_string_put(data->mlx.connection, data->mlx.window, x, *y, 0x03fc35, line);
    free(itoa_tmp);
    free(line);
}

void scaling_factor(t_data *data, int x_margin, int *y_margin, int sf)
{
    char *menu;

    *y_margin += 15;
    menu = "|scaling-factor:";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    mlx_put_dynamic_line(data, x_margin, y_margin, "                     ", sf);
    menu = "                             |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
}

void translation_factor(t_data *data, int x_margin, int *y_margin, int tf)
{
    char *menu;

    *y_margin += 15;
    menu = "|translation-factor:";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    mlx_put_dynamic_line(data, x_margin, y_margin, "                     ", tf);
    menu = "                             |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
}
void rotation_angle(t_data *data, int x_margin, int *y_margin, int angle)
{
    char *menu;

    *y_margin += 15;
    menu = "|rotation-angle:";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    mlx_put_dynamic_line(data, x_margin, y_margin, "                     ", angle);
    menu = "                             |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
}

void    x_menu(t_data *data, int x_margin, int *y_margin)
{
    char *menu;
    *y_margin += 15;
    menu = "| - - - - - x-axis - - - - --|";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    scaling_factor(data, x_margin, y_margin, data->params.sf_x);
    translation_factor(data, x_margin, y_margin, data->params.tf_x);
    rotation_angle(data, x_margin, y_margin, data->params.x_angle);
}

void    y_menu(t_data *data, int x_margin, int *y_margin)
{
    char *menu;

    *y_margin += 15; 
    menu = "| - - - - - y-axis - - - - --|";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    scaling_factor(data, x_margin, y_margin, data->params.sf_y);
    translation_factor(data, x_margin, y_margin, data->params.tf_y);
    rotation_angle(data, x_margin, y_margin, data->params.y_angle);
}

void    z_menu(t_data *data, int x_margin, int *y_margin)
{
    char *menu;

    *y_margin += 15;
    menu = "| - - - - - z-axis - - - - --|";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    scaling_factor(data, x_margin, y_margin, data->params.sf_z);
    translation_factor(data, x_margin, y_margin, data->params.tf_z);
    rotation_angle(data, x_margin, y_margin, data->params.z_angle);
}

void    axis_menu(t_data *data, int x_margin, int *y_margin)
{
    x_menu(data, x_margin, y_margin);
    y_menu(data, x_margin, y_margin);
    z_menu(data, x_margin, y_margin);
}

void    basic_instructions(t_data *data, int x_margin, int *y_margin)
{
    char *menu;

    menu = "| - - - - - Instructions - - - - - - - - - - |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'ESC' - exit the program                   |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'i' - zoom in                              |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'd' - zoom out                             |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'r' - reset the object                     |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
}

void    rotation_instructions(t_data *data, int x_margin, int *y_margin)
{
    char *menu;

    *y_margin += 15;
    menu = "| '1 and 2' - rotate on x-axis               |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| '3 and 4' - rotate on y-axis               |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| '5 and 6' - rotate on z-axis               |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
}

void translation_instructions(t_data *data, int x_margin, int *y_margin)
{
    char *menu;

    *y_margin += 15;
    menu = "| 'Left, Right'        - translate on x-axis |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'Up, Down'           - translate on y-axis |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'Page Up, Page Down' - translate on z-axis |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin,* y_margin, 0x03fc35, menu);
}

void scaling_instructions(t_data *data, int x_margin, int *y_margin)
{
    char *menu;

    *y_margin += 15;
    menu = "| 'w' - increase x-axis scaling factor       |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'q' - decrease x-axis scaling factor       |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 's' - increase y-axis scaling factor       |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
    *y_margin += 15;
    menu = "| 'a' - decrease y-axis scaling factor       |";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, *y_margin, 0x03fc35, menu);
}

void    instructions(t_data *data, int x_margin)
{
    int  y_margin;

    y_margin = 250;
    basic_instructions(data,x_margin, &y_margin);
    rotation_instructions(data, x_margin, &y_margin);
    translation_instructions(data, x_margin, &y_margin);
    scaling_instructions(data, x_margin, &y_margin);

}

void    display_menu(t_data *data)
{
    char *menu;
    int x_margin;
    int y_margin;

    x_margin = 10;
    y_margin = 30;

    menu = "------- [FDF] Menu -------";
    mlx_string_put(data->mlx.connection, data->mlx.window, x_margin, y_margin, 0x03fc35, menu);
    axis_menu(data, x_margin, &y_margin);
    instructions(data, x_margin);
}