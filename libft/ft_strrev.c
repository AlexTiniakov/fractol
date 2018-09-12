/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 17:09:37 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/23 17:15:52 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrev(char *str)
{
	char	tab;
	int		len;
	int		i;

	len = ft_strlen(str);
	i = -1;
	while (++i < --len)
	{
		tab = str[i];
		str[i] = str[len];
		str[len] = tab;
	}
}
