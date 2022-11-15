/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:43:08 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/04 14:53:18 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_arg(int errcode)
{
	if (errcode == ID_ERROR_WRONG_FRACTAL_NAME)
		ft_printf("%s", ERROR_WRONG_FRACTAL_NAME);
	else if (errcode == ID_ERROR_FLOAT)
		ft_printf("%s", ERROR_FLOAT);
	else if (errcode == ID_ERROR_NBR_ARG)
		ft_printf("%s", ERROR_NBR_ARG);
	ft_printf("%s", ERROR_EXEMPLE);
}

int	ft_check_arg(int argc, char **argv)
{
	char	*fractal_name;

	if (argc != 2 && argc != 4)
		return (0);
	if (argc == 2)
	{
		fractal_name = ft_strtocase(argv[1], ft_tolower);
		if (ft_strncmp(fractal_name, "julia", ft_strlen(argv[1]))
			|| ft_strncmp(fractal_name, "mandelbrot", ft_strlen(argv[1])))
			return (ID_ERROR_WRONG_FRACTAL_NAME);
	}
	return (0);
}
