/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:18:27 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/03 17:50:49 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	render_square(t_window mlx)
{
	t_data	img;
	int		i;
	int		j;
	int		square_len;

	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	i = 0;
	j = 540;
	while (i < 1980)
	{
		my_mlx_pixel_put(&img, i, j, encode_rgb(48, 48, 48));
		i += 3;
	}
	i = 960;
	j = 0;
	while (j < 1080)
	{
		my_mlx_pixel_put(&img, i, j, encode_rgb(48, 48, 48));
		j += 3;
	}
	i = 0;
	square_len = 42;
	while (i <= square_len)
	{
		j = 0;
		while (j <= square_len)
		{
			my_mlx_pixel_put(&img, i + 960 - (square_len / 2), j + 540 - (square_len / 2), encode_rgb(255, 255, 255));
			j++;
		}
		i++;
	}
	return (img);
}
