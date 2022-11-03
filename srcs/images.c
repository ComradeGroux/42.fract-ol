/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:18:27 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/03 14:20:53 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	render_square(t_window mlx)
{
	t_data	img;
	int		i;
	int		j;

	img.img = mlx_new_image(mlx.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	i = 0;
	while (i <= 42)
	{
		j = 0;
		while (j <= 42)
		{
			my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	return (img);
}
