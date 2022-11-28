/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:10:38 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/28 16:57:00 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	choose_color(int iter, double zr2, double zi2)
{
	double	t;

	t = ((double)iter + 2 - log(log(zr2 + zi2)) / M_LN2) / 10;
	t /= 5;
	return (encode_rgb(t, 0, t));
}

int	encode_rgb(double r, double g, double b)
{
	return (((int)(r * 255) << 16) + ((int)(g * 255) << 8) + (int)(b * 255));
}
