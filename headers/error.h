/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:00:22 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/25 13:39:46 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ID_ERROR_WRONG_FRACTAL_NAME 1
# define ERROR_WRONG_FRACTAL_NAME  "Mauvais non de fractal.\n"

# define ID_ERROR_NBR_ARG 2
# define ERROR_NBR_ARG "Nombre d'arguments non valide.\n"

# define ID_ERROR_FLOAT 3
# define ERROR_FLOAT "Vous devez entrer un nombre a virgule pour generer \
un ensemble de Julia\n"

# define ERROR_EXEMPLE "Exemple d'utilisation:\n \
	Fractal de Mandelbrot:		./fractol mandelbrot\n \
	Fractal de Julia:		./fractal julia 0.28 0.01\n\n"

#endif