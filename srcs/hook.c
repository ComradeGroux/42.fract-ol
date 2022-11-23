/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:27:34 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/23 18:42:20 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    update_f(t_data *data, double zoom)
{
    data->x_max *= zoom;
    data->x_min *= zoom;
    data->y_min *= zoom;
    data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		exit(1);
    if (keycode == ARROW_UP)
        update_f(data, 0.95);
    if (keycode == ARROW_DOWN)
        update_f(data, 1.05);
    fractal_render(data);
	return (0);
}
