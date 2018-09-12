/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 16:08:11 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/28 16:08:13 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_clean(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	ft_memdel((void **)&s1);
	ft_memdel((void **)&s2);
	return (str);
}
