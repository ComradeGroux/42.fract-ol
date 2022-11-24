/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:10:38 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/24 15:53:28 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	choose_fractal(char *name)
{
	if (ft_strncmp(name, "mandelbrot", ft_strlen(name)))
		return (FRACTAL_TYPE_MANDELBROT);
	else if (ft_strncmp(name, "julia", ft_strlen(name)))
		return (FRACTAL_TYPE_JULIA);
}
