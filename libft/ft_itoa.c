/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:58:47 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/30 13:46:53 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n, int i)
{
	if (n == -2147483648)
		return (12);
	i = n < 0 ? 1 : 0;
	n = n < 0 ? -n : n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	i += 1;
	return (i);
}

static void	put(char *str, int n)
{
	if (n >= 10)
		put(str + 1, n / 10);
	*str = (n % 10) + '0';
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(count(n, 0));
	if (n == -2147483648)
	{
		ft_strcpy(str, "-2147483648");
		return (str);
	}
	if (!str)
		return (NULL);
	if (n < 0)
		str[i++] = '-';
	n = (n < 0) ? -n : n;
	put(&str[i], n);
	ft_strrev(&str[i]);
	return (str);
}
