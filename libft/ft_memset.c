/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 13:20:38 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/22 16:57:04 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tab;

	tab = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (--len + 1)
		tab[len] = *(unsigned char *)&c;
	return (b);
}
