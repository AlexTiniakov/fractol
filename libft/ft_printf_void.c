/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_void.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:06:38 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/22 17:40:15 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t	ft_putnbr_front_p(uintmax_t j, char *base, t_p *p, char *front)
{
	uintmax_t	j_len;
	size_t		front_len;

	front_len = 2;
	j_len = ft_len_j(j, base, NULL, p) + front_len;
	if (p->is_width && !p->minus && !p->zero)
	{
		ft_probels(j_len, p->width, ' ');
		front_len += _MAX(p->width - (int)j_len, 0);
		p->is_width = 0;
	}
	else if (p->is_width)
		p->width -= front_len;
	if (front_len)
		write(1, front, 2);
	return (ft_putnbr_unsign(j, base, p, NULL) + front_len);
}

intmax_t		ft_printf_void(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	(void)str;
	p->size = 'z';
	get_u(ap, p, &u);
	p->zero = p->is_precision ? 0 : p->zero;
	return (ft_putnbr_front_p(u, _HEXL, p, "0x"));
}
