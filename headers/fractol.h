/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:19:14 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/04 17:46:38 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "color.h"
# include "hook.h"
# include "error.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define MAX_I 42

# define WIDTH 1920
# define HEIGHT 1080

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
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp;
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

#endif