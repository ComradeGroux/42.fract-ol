/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:54:23 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/25 13:54:48 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		type;
	int		x;
	int		y;
	int		iter;
	double	x_off;
	double	y_off;
	double	jr;
	double	ji;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_data;

int		main(int argc, char **argv);
void	mlx_start(t_data *data);
void	fractal_render(t_data *data);
void	mandelbrot(t_data *data);
void	mandel_calc(t_data *data, int x, int y);
void	put_pixel(t_data *data, int x, int y, int color);
void	update_f(t_data *data, double zoom);
void	move_f(t_data *data, int x, int y);
int		key_hook(int keycode, t_data *data);
int		mouse_hook(int mousecode, int x, int y, t_data *data);
void	ft_error_arg(int errcode);
int		ft_check_arg(t_data *data, int argc, char **argv);
void	julia_calc(t_data *data, int x, int y);
void	julia(t_data *data);
int		choose_fractal(char *name);
int		fractol_exit(t_data *data);
int		check_double(char *str);

#endif