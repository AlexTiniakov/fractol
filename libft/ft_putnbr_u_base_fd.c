/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u_base_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 22:06:21 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/10 22:06:22 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_u_base_fd(uintmax_t nbr, char *base, int fd)
{
	uintmax_t len;

	len = ft_strlen(base);
	if (nbr / len)
		ft_putnbr_u_base_fd(nbr / len, base, fd);
	write(fd, (base + nbr % len), 1);
}
