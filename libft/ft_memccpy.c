/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:32:57 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/21 11:43:09 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,\
					size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = -1;
	if (n)
		while (++i < (int)n)
		{
			a[i] = b[i];
			if (b[i] == *(unsigned char *)&c)
				return ((void *)&(a[i + 1]));
		}
	return (NULL);
}
