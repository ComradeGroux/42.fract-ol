/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:00:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/02 23:20:43 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ID_ERROR_WRONG_FRACTAL_NAME 1
# define ERROR_WRONG_FRACTAL_NAME  "Mauvais non de fractal.\n"
# define ERROR_NBR_ARG "Nombre d'arguments non valide.\n"
# define ERROR_FLOAT "Vous devez entrer un nombre a virgule pour generer \
	un ensemble de Julia\n"
# define ERROR_EXEMPLE "Exemple d'utilisation:\n \
	Fractal de Mandelbrot:		./fractol mandelbrot\n \
	Fractal de Julia:			./fractal 0.28 0.01 julia\n\n"

int	ft_error_arg(char *error);
int	ft_check_arg(int argc, char **argv);

#endif