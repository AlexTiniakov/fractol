/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:28:06 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/22 16:24:19 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *v;
	char c;

	c = 0;
	v = malloc(size);
	if (!v)
		return (NULL);
	ft_memset(v, 0, size);
	return (v);
}
