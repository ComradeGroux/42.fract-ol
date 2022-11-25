/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:10:38 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/25 17:22:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	color_multi(double iter)
{
	double	r;
	double	g;
	double	b;
	int		color;

	r = cos(0.333 * iter);
	g = cos(0.333 * iter);
	b = cos(0.333 * iter);
	color = ((int)(255.999 * r) << 16) + ((int)(255.999 * g) << 8)
		+ ((int)(255.999 * b));
	return (color);
}
