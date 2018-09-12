/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:32:35 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/31 15:42:30 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = -1;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[++i])
		if (needle[0] == haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j])
				if (!needle[++j])
					return ((char *)(haystack + i));
		}
	return (NULL);
}
