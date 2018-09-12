/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 14:35:48 by otiniako          #+#    #+#             */
/*   Updated: 2018/06/02 14:35:49 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoi_long(const char *str)
{
	intmax_t nb[2];

	nb[0] = 0;
	nb[1] = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str != '-' && *str != '+' && (*str < '0' || *str > '9'))
		return (0);
	if (*str == '-')
	{
		nb[1] = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb[0] *= 10;
		nb[0] += (int)*str++ - '0';
	}
	return ((nb[1] == 1) ? (intmax_t)(-nb[0]) : (intmax_t)(nb[0]));
}
