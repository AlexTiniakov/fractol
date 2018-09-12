/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 22:36:57 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/17 22:36:59 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_printf_long(char **str, va_list *ap, t_p *p)
{
	p->size = 'l';
	return (ft_get_fun(ft_tolower(**str))(str, ap, p));
}
