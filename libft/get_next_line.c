/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 19:25:40 by otiniako          #+#    #+#             */
/*   Updated: 2018/04/20 20:46:44 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_joy(char **str, char *buf, char *tab)
{
	tab = ft_strnew(ft_strlen(*str));
	tab = ft_strcpy(tab, *str);
	ft_memdel((void **)str);
	*str = ft_strjoin(tab, buf);
	ft_memdel((void **)&tab);
}

static int	ft_check(char **str, char **line, char *tab)
{
	tab = ft_strchr(*str, '\n');
	if (tab)
	{
		*line = ft_strsub(*str, 0, tab - *str);
		ft_memmove(*str, tab + 1, ft_strlen(tab));
		return (1);
	}
	return (0);
}

static int	ft_read(int fd, char **str, char **line, int ret)
{
	char buf[BUFF_SIZE + 1];

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		if (*str)
			ft_joy(str, buf, NULL);
		else
			*str = ft_strdup(buf);
		if (ft_check(str, line, NULL))
			return (1);
	}
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	**str = NULL;
	int			rez;

	if (!str)
		str = (char **)malloc(sizeof(*str) * 4864);
	if (!line || fd < 0 || fd > 4864 || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] && ft_check(&str[fd], line, NULL))
		return (1);
	rez = ft_read(fd, &str[fd], line, -1);
	if (rez != 0)
		return (rez);
	if (str[fd] == NULL || str[fd][0] == '\0')
		return (0);
	*line = str[fd];
	str[fd] = NULL;
	return (1);
}
