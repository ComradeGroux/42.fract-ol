/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:43:08 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/02 17:41:34 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error.h"

int	ft_error_arg(char *error)
{
	ft_printf("%s", error);
	return (1);
}

int	ft_check_arg(int argc, char **argv)
{
	char	*fractal_name;

	if (argc != 2 && argc != 4)
		return (0);
	if (argc == 2)
	{
		fractal_name = ft_tolower(argv[1]);
		if (ft_strncmp(fractal_name, "julia", ft_strlen(argv[1]))
			|| ft_strncmp(fractal_name, "mandelbrot", ft_strlen(argv[1])))
			return (ERROR_WRONG_FRACTAL_NAME);
	}
	return (1);
}
