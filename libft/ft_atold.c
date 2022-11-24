/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:55:26 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/24 16:14:50 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double	ft_atold(char *str)
{
	long double	nb;
	long double	part;
	long double	sign;
	int			i;

	sign = 1.0;
	i = 0;
	nb = 0.0;
	part = 0.0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1.0;
	while (str[i] && str[i] >= 0 && str[i] <= 9)
		nb = nb * 10 + (str[i++] - '0');
	if (str[i] == '.' || str[i] == ',')
	{
		while (str[i] && str[i] >= 0 && str[i] <= 9)
			i++;
		while (str[i] && str[i] >= 0 && str[i] <= 9)
			part = (part + (str[i--] - '0')) / 10.0;
		nb += part;
	}
	return (nb * sign);
}
