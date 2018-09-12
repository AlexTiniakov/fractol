/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 22:57:52 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/17 22:57:53 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_printf_wchar(char **str, va_list *ap, t_p *p)
{
	wchar_t		c;
	uintmax_t	c_len;

	(void)str;
	c = (wchar_t)va_arg(*ap, wint_t);
	if (c <= 0x7F)
		c_len = 1;
	else if (c <= 0x7FF)
		c_len = 2;
	else if (c <= 0xFFFF)
		c_len = 3;
	else if (c <= 0x10FFFF)
		c_len = 4;
	else
		c_len = 0;
	if (p->is_width && !p->minus)
		ft_probels(c_len, p->width, p->zero ? '0' : ' ');
	ft_putwchar(c);
	if (p->is_width && p->zero)
		ft_probels(c_len, p->width, p->zero ? '0' : ' ');
	return (p->is_width ? ft_max(c_len, (uintmax_t)p->width) : c_len);
}

intmax_t	ft_printf_char(char **str, va_list *ap, t_p *p)
{
	char c;

	(void)str;
	if (p->size == 'l')
		return (ft_printf_wchar(str, ap, p));
	if (p->is_width && !p->minus)
		ft_probels(1, p->width, p->zero ? '0' : ' ');
	c = va_arg(*ap, int);
	write(1, &c, 1);
	if (p->is_width && p->minus)
		ft_probels(1, p->width, ' ');
	return (p->is_width ? ft_max(p->width, 1) : 1);
}
