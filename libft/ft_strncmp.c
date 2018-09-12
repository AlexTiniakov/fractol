/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:32:17 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 13:00:13 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	return ((*s1 && *s2 && *s1 == *s2 && n - 1) ?\
			ft_strncmp(++s1, ++s2, --n) : ((unsigned char)*s1 - (unsigned char)\
											*s2));
}
