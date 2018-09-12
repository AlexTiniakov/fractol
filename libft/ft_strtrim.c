/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:14:38 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/29 16:20:31 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		i;

	i = 0;
	if (s && *s)
	{
		len = ft_strlen(s);
		while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\n' ||\
							s[len - 1] == '\t'))
			len--;
		if (!len)
			return (ft_strnew(0));
		while (i < len && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		return (ft_strsub(s, i, len - i));
	}
	else if (s)
		return (ft_strnew(0));
	else
		return (NULL);
}
