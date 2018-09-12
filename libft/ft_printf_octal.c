/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:09:33 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/21 23:09:34 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_printf_octal(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	(void)str;
	get_u(ap, p, &u);
	if (p->reshetka && u == 0 && p->is_precision && p->precision == 0)
	{
		if (p->is_width && !p->minus)
			ft_probels(1, p->width, p->zero ? '0' : ' ');
		write(1, "0", 1);
		if (p->is_width && p->minus)
			ft_probels(1, p->width, ' ');
		return (p->is_width ? ft_max(p->width, 1) : 1);
	}
	if (p->reshetka && u != 0)
	{
		p->is_precision = 1;
		p->precision = _MAX(p->precision, (int)(ft_len(u, _OCT) + 1));
	}
	return (ft_putnbr_unsign(u, _OCT, p, NULL));
}
