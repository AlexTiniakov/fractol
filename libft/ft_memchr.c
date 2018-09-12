/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:15:39 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/21 11:43:31 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*str;
	int				i;

	i = -1;
	chr = (unsigned char)c;
	str = (unsigned char *)s;
	if (n)
		while (++i < (int)n)
			if (str[i] == chr)
				return ((void *)(str + i));
	return (NULL);
}
