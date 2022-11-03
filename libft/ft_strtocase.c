/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtocase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgroux <vgroux@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:55:09 by vgroux            #+#    #+#             */
/*   Updated: 2022/11/03 00:02:58 by vgroux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtocase(char *s, int (*f)(int))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		s[i] = f(s[i]);
		i++;
	}
	return (s);
}