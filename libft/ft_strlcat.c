/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:22:58 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/29 13:15:31 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int		i;
	size_t	j;
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = (int)d_len;
	j = 0;
	if (dstsize < d_len + 1)
		return (s_len + dstsize);
	else
		while (i < (int)(dstsize - 1))
			*(dst + i++) = *(src + j++);
	*(dst + i) = '\0';
	return (s_len + d_len);
}
