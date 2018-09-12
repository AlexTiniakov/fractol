/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:53:16 by otiniako          #+#    #+#             */
/*   Updated: 2018/07/25 19:53:18 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *str)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = ft_strnew(ft_strlen(str) + 1);
	while (str[++i])
		tmp[i] = (char)ft_toupper(str[i]);
	return (tmp);
}
