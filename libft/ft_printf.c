/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 21:47:19 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/10 21:47:33 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fun			ft_get_fun(char c)
{
	static t_fun *fun = NULL;

	if (fun == NULL)
	{
		if ((fun = ft_memalloc(sizeof(*fun) * 256)) != NULL)
		{
			fun['%'] = &ft_printf_procent;
			fun['i'] = &ft_printf_int;
			fun['d'] = &ft_printf_int;
			fun['D'] = &ft_printf_long;
			fun['c'] = &ft_printf_char;
			fun['C'] = &ft_printf_wchar;
			fun['s'] = &ft_printf_str;
			fun['S'] = &ft_printf_wstr;
			fun['x'] = &ft_printf_hex;
			fun['X'] = &ft_printf_hex;
			fun['o'] = &ft_printf_octal;
			fun['O'] = &ft_printf_long;
			fun['u'] = &ft_printf_unsigned;
			fun['U'] = &ft_printf_long;
			fun['p'] = &ft_printf_void;
		}
	}
	return (fun[(int)c]);
}

static int		is_str(char **str)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
		|| **str == ' ')
		return (1);
	if (**str == '.' || **str == '*' || ft_isdigit(**str))
		return (1);
	if (**str == 'h' || **str == 'l' || **str == 'j' || **str == 'z')
		return (1);
	return (0);
}

static ssize_t	ft_2(ssize_t rez, t_p *p, char **str, va_list *ap)
{
	t_fun	fun;

	if ((*(++*str)) == '\0')
		return (0);
	p->size = '\0';
	while (is_str(str) == 1)
	{
		ft_check_flags(str, p);
		ft_check_width(str, p, ap);
		ft_check_precision(str, p, ap, 0);
		ft_check_size(str, p, '\0');
	}
	if (**str == '\0')
		return (0);
	if ((fun = ft_get_fun(**str)) == NULL)
		fun = ft_null;
	rez = fun(str, ap, p);
	(*str)++;
	return (rez);
}

static int		ft_1(size_t rez, va_list *ap, const char *str)
{
	char	*next;
	t_p		p;
	ssize_t	r;

	next = ft_strchr(str, '%');
	if (*str == '\0')
		return (rez);
	if (next == NULL)
		return (rez + write(1, str, ft_strlen(str)));
	else if (next > str)
		return (ft_1(rez + write(1, str, next - str), ap, next));
	else
	{
		ft_bzero(&p, sizeof(p));
		return ((r = ft_2(0, &p, (char **)&str, ap)) == -1 ? -1 : ft_1(rez +\
					r, ap, str));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rez;

	va_start(ap, format);
	rez = ft_1(0, &ap, format);
	va_end(ap);
	return (rez);
}
