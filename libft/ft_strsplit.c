/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:20:55 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/29 16:23:05 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countn(char const *s, char c, int i)
{
	while (*s == c && *s)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c && *s)
				s++;
			if (*s)
				i++;
		}
		if (*s)
			s++;
	}
	return (i);
}

static int	count(char const *s, char c, int i)
{
	while (*s != c && *s)
	{
		i++;
		s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	str = s ? (char **)malloc(sizeof(str) * (countn(s, c, 1) + 1)) : NULL;
	if (!str)
		return (NULL);
	while (*s)
	{
		j = -1;
		if (*s == c)
			s++;
		else
		{
			str[i] = (char *)malloc(count(s, c, 0) + 1);
			while (*s != c && *s)
				str[i][++j] = *s++;
			str[i][++j] = '\0';
			i++;
		}
	}
	str[i] = NULL;
	return (str);
}
