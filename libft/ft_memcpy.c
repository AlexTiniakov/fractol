/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:06:04 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/28 16:16:30 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	if (n == 0 || dst == src)
		return (dst);
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	while (n--)
		*a++ = *b++;
	return (dst);
}
