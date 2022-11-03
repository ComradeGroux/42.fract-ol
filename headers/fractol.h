/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:19:14 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/03 14:28:59 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "hook.h"
# include "error.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>

typedef struct s_window
{
	void	*mlx;
	void	*win;
}	t_window;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

int			main(int argc, char **argv);
t_window	create_window(void);
int			close_window(int keycode, t_window *mlx);
t_data		render_square(t_window mlx);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif