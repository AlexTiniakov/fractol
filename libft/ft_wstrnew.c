/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:50:28 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/04 11:50:29 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t *str;
	int		i;

	i = 0;
	str = (wchar_t *)malloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	while ((size_t)i <= size)
		str[i++] = 0;
	return (str);
}
