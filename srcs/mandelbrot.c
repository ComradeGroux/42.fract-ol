/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 15:26:19 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/04 18:02:52 by vgroux           ###   ########.fr       */
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
		while (y < HEIGHT)
		{
			mandel_calc(data, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	mandel_calc(t_data *data, int x, int y)
{
	data->cr = (double)x / WIDTH * 4 - 2;
	data->ci = (double)y / HEIGHT * 4 - 2;
	data->zr = 0;
	data->zi = 0;
	data->iter = 0;
	put_pixel(data, x, y, 0xFFFFFF);
	return;
	//while (pow(data->zr, 2) + pow(data->zi, 2) <= 4 && data->iter < MAX_I)
	while (fabs(data->zr + data->zi) <= 16 && data->iter < MAX_I)
	{
		data->tmp = data->zr;
		data->zr = pow(data->zr, 2) - pow(data->zi, 2) + data->cr;
		data->zi = 2 * data->zi * data->tmp + data->ci;
		data->iter++;
	}
	if (data->iter == MAX_I)
		put_pixel(data, x, y, 0xFFFFF);
	else
		put_pixel(data, x, y, 0xFFFFF);
}
