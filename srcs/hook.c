/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:27:34 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/25 13:29:03 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	update_f(t_data *data, double zoom)
{
	data->x_max *= zoom;
	data->x_min *= zoom;
	data->y_min *= zoom;
	data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
}

void	move_f(t_data *data, int x, int y)
{
	data->x_off += x;
	data->y_off -= y;
}

void	change_input(t_data *data, double up)
{
	data->jr += up;
	data->ji += up;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		fractol_exit(data);
	if (keycode == ARROW_UP)
		move_f(data, 0, 15);
	if (keycode == ARROW_DOWN)
		move_f(data, 0, -15);
	if (keycode == ARROW_LEFT)
		move_f(data, -15, 0);
	if (keycode == ARROW_RIGHT)
		move_f(data, 15, 0);
	if (keycode == PLUS)
		change_input(data, 0.001);
	if (keycode == MINUS)
		change_input(data, -0.001);
	fractal_render(data);
	return (0);
}

int	mouse_hook(int mousecode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (mousecode == ZOOM_IN)
		update_f(data, 0.90);
	if (mousecode == ZOOM_OUT)
		update_f(data, 1.10);
	fractal_render(data);
	return (0);
}
