/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 14:37:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/28 15:13:07 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		err;

	err = ft_check_arg(&data, argc, argv);
	if (err == 0)
	{
		data.type = choose_fractal(ft_strtocase(argv[1], ft_tolower));
		mlx_start(&data);
//		fractal_render(&data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_mouse_hook(data.win, &mouse_hook, &data);
		mlx_hook(data.win, 17, 0, &fractol_exit, &data);
		mlx_loop_hook(data.mlx, &fractal_render, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_error_arg(err);
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
	data->x_min = -2.0 * ((double)WIDTH / (double)HEIGHT);
	data->y_min = -2.0;
	data->y_max = data->y_min + (data->x_max - data->x_min) * HEIGHT / WIDTH;
	data->y_off = 0;
	data->x_off = 0;
}

int	fractal_render(t_data *data)
{
	if (data->type == FRACTAL_TYPE_MANDELBROT)
		mandelbrot(data);
	else if (data->type == FRACTAL_TYPE_JULIA)
		julia(data);
	else if (data->type == -1)
		exit (1);
	return (0);
}

int	choose_fractal(char *name)
{
	if (!ft_strncmp(name, "mandelbrot", ft_strlen(name)))
		return (FRACTAL_TYPE_MANDELBROT);
	else if (!ft_strncmp(name, "julia", ft_strlen(name)))
		return (FRACTAL_TYPE_JULIA);
	return (-1);
}
