/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 11:44:47 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 12:37:21 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	if (s && f)
	{
		str = ft_strnew(ft_strlen(s));
		if (!str)
			return (NULL);
		while (*s)
		{
			if (f(*s))
				str[++i] = f(*s);
			s++;
		}
	}
	return (str);
}
