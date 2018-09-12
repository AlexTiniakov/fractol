/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:57:05 by otiniako          #+#    #+#             */
/*   Updated: 2018/02/28 17:50:30 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(intmax_t nbr, char *base)
{
	write(1, "-", _NEGATIVE(nbr));
	ft_putnbr_u_base_fd(_ABS(nbr), base, 1);
}
