/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:31:48 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/22 17:41:46 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t	ft_all_wstrlen(wchar_t *str, int precision, intmax_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (ft_all_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (ft_all_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (ft_all_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (ft_all_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

intmax_t		ft_printf_wstr(char **str, va_list *ap, t_p *p)
{
	wchar_t		*tmp;
	intmax_t	len;

	(void)str;
	(void)p;
	tmp = va_arg(*ap, wchar_t*);
	tmp = tmp == NULL ? L"(null)" : tmp;
	len = p->is_precision ? ft_all_wstrlen(tmp, p->precision, 0) :\
			ft_wstrlen(tmp);
	if (p->is_width && !p->minus)
		ft_probels(len, p->width, p->zero ? '0' : ' ');
	ft_putnwstr(tmp, len);
	if (p->is_width && p->minus)
		ft_probels(len, p->width, ' ');
	return (p->is_width ? ft_max(len, p->width) : len);
}

intmax_t		ft_printf_str(char **str, va_list *ap, t_p *p)
{
	char		*tmp;
	intmax_t	len;
	intmax_t	tmp_len;

	if (p->size == 'l')
		return (ft_printf_wstr(str, ap, p));
	tmp = va_arg(*ap, char*);
	tmp = tmp == NULL ? "(null)" : tmp;
	tmp_len = ft_strlen(tmp);
	len = p->is_precision ? ft_min(tmp_len, p->precision) : tmp_len;
	if (p->is_width && !p->minus)
		ft_probels(len, p->width, p->zero ? '0' : ' ');
	write(1, tmp, len);
	if (p->is_width && p->minus)
		ft_probels(len, p->width, ' ');
	return (p->is_width ? ft_max(len, p->width) : len);
}
