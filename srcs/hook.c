/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:53:11 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/25 15:54:49 by vgroux           ###   ########.fr       */
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

void	reset(t_data *data)
{
	data->x_max = 2.0;
	data->x_min = -2.0;
	data->y_min = -2.0;
	data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
	data->x_off = 0;
	data->y_off = 0;
}
