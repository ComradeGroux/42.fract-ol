/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:26:19 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/23 15:31:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		data->cr = (data->x_max - x) * ((data->x_max - data->x_min) / WIDTH);
		while (y < HEIGHT)
		{
			data->ci = (data->y_min - y) * ((data->y_max - data->y_min) / HEIGHT);
			mandel_calc(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

#include <stdio.h>
void	mandel_calc(t_data *data, int x, int y)
{
	double	zr2;
	double	zi2;

	data->iter = 0;
	data->zr = data->cr;
	data->zi = data->ci;
	while (data->iter < MAX_I)
	{
		zr2 = pow(data->zr, 2);
		zi2 = pow(data->zi, 2);
		if (zr2 + zi2 > 4)
			break ;
		data->zi = 2 * data->zr * data->zi + data->ci;
		data->zr = zr2 - zi2 + data->cr;
		data->iter++;
	}
	if (data->iter == MAX_I)
		put_pixel(data, x, y, 0x000000);
	else
		put_pixel(data, x, y, 0xFFFFFF);
}
