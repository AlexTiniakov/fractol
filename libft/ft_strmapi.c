/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 12:18:38 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 12:37:10 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			if (f(++i, *s))
				str[i] = f(i, *s);
			s++;
		}
	}
	return (str);
}
