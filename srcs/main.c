/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:37:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/23 18:43:39 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;
	/*int		err;

	err = ft_check_arg(argc, argv);
	if (err == 0)
	{*/
	(void)argc;
	(void)argv;
	data.type = 1;
	mlx_start(&data);
	fractal_render(&data);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_loop(data.mlx);
	/*
	else
		ft_error_arg(err);*/
	return (0);
}

void	mlx_start(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_len, &data->endian);
	data->x_max = 2.0;
	data->x_min = -2.0;
	data->y_min = -2.0;
	data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
	data->y_off = 0;
	data->x_off = 0;
	data->zoom = 260;
}

void	fractal_render(t_data *data)
{
	mandelbrot(data);/*
	else if (data.type == 2)
		julia(data);*/
}
