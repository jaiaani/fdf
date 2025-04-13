#include "../fdf.h"

void	zoom(int keysym, t_data *data)
{
	if (keysym == XK_i)
	{
		data->params.sf_x += 1;
		data->params.sf_y += 1;
		data->params.sf_z += 1;
	}
	if (keysym == XK_d)
	{
		data->params.sf_x -= 1;
		data->params.sf_y -= 1;
		data->params.sf_z -= 1;
	}
}

void	scale(int keysym, t_data *data)
{
	int	scale_step;

	scale_step = 5;
	if (keysym == XK_w)
		data->params.sf_x += scale_step;
	if (keysym == XK_q)
		data->params.sf_x -= scale_step;
	if (keysym == XK_s)
		data->params.sf_y += scale_step;
	if (keysym == XK_a)
		data->params.sf_y -= scale_step;
	if (keysym == XK_x)
		data->params.sf_z += scale_step;
	if (keysym == XK_z)
		data->params.sf_z -= scale_step;
}

void	rotate(int keysym, t_data *data)
{
	float	angle_step;

	angle_step = 10.0;
	if (keysym == XK_1)
		data->params.x_angle -= angle_step;
	if (keysym == XK_2)
		data->params.x_angle += angle_step;
	if (keysym == XK_3)
		data->params.y_angle -= angle_step;
	if (keysym == XK_4)
		data->params.y_angle += angle_step;
	if (keysym == XK_5)
		data->params.z_angle -= angle_step;
	if (keysym == XK_6)
		data->params.z_angle += angle_step;
}

void	translate(int keysym, t_data *data)
{
	int	translate_step;

	translate_step = 10;
	if (keysym == XK_Left)
		data->params.tf_x -= translate_step;
	if (keysym == XK_Right)
		data->params.tf_x += translate_step;
	if (keysym == XK_Up)
		data->params.tf_y -= translate_step;
	if (keysym == XK_Down)
		data->params.tf_y += translate_step;
	if (keysym == XK_Page_Up)
		data->params.tf_z -= translate_step;
	if (keysym == XK_Page_Down)
		data->params.tf_z += translate_step;
}

void	reset(int keysym, t_data *data)
{
	if (keysym == XK_r)
	{
		data->dot.x = 0;
		data->dot.y = 0;
		data->dot.z = 0;
		data->dot.color = 0xffffff;
		data->params.zoom = 8;
		data->params.sf_x = data->params.zoom;
		data->params.sf_y = data->params.zoom;
		data->params.sf_z = data->params.zoom;
		data->params.tf_x = 0;
		data->params.tf_y = 0;
		data->params.tf_z = 0;
		data->params.x_angle = 0.0;
		data->params.y_angle = 0.0;
		data->params.z_angle = 0.0;
	}
}