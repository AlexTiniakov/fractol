/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 10:43:17 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/11 10:43:18 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_check_flags(char **str, t_p *p)
{
	if (**str == '#' || **str == '0' || **str == '-' || **str == '+'
		|| **str == ' ')
	{
		if (**str == '#')
			p->reshetka = 1;
		else if (**str == '0')
			p->zero = 1;
		else if (**str == '-')
			p->minus = 1;
		else if (**str == '+')
			p->plus = 1;
		else if (**str == ' ')
			p->probel = 1;
		(*str)++;
		if (p->minus == 1)
			p->zero = 0;
		return (ft_check_flags(str, p));
	}
	else
		return (*str);
}

char	*ft_check_width(char **str, t_p *p, va_list *ap)
{
	int i;

	i = p->width ? p->width : 0;
	p->width = 0;
	while (**str == '*' || ft_isdigit(**str))
	{
		p->is_width = 1;
		if (**str == '*')
		{
			(*str)++;
			p->width = va_arg(*ap, int);
			p->minus = p->width < 0 ? 1 : p->minus;
			p->width = _ABS(p->width);
		}
		if (ft_isdigit(**str))
		{
			p->width = 0;
			while (ft_isdigit(**str))
				p->width = p->width * 10 + (*(*str)++ - '0');
		}
	}
	p->width = p->width ? p->width : i;
	return (*str);
}

char	*ft_check_precision(char **str, t_p *p, va_list *ap, int pr)
{
	if (**str == '.')
	{
		p->is_precision = 0;
		p->precision = 0;
		(*str)++;
		if (**str == '*')
		{
			(*str)++;
			if ((pr = va_arg(*ap, int)) >= 0)
			{
				p->is_precision = 1;
				p->precision = pr;
			}
			return (*str);
		}
		else
		{
			while (ft_isdigit(**str))
				p->precision = p->precision * 10 + (*(*str)++ - '0');
			p->is_precision = 1;
			return (*str);
		}
	}
	return (*str);
}

char	*ft_check_size(char **str, t_p *p, char c)
{
	if (**str == 'h')
	{
		c = *(*str + 1) == 'h' ? 'H' : 'h';
		p->size = c == 'H' && p->size == '\0' ? 'H' : p->size;
		p->size = c == 'h' && (p->size == 'H' || !p->size) ? 'h' : p->size;
		return (*str += c == 'h' ? 1 : 2);
	}
	if (**str == 'l')
	{
		c = *(*str + 1) == 'l' ? 'L' : 'l';
		p->size = c == 'l' && (_SCR1 || !p->size) ? c : p->size;
		p->size = c == 'L' && (_SCR2 || !p->size) ? c : p->size;
		return (*str += c == 'l' ? 1 : 2);
	}
	if (**str == 'j')
	{
		p->size = p->size == 'z' ? p->size : 'j';
		return ((*str)++);
	}
	if (**str == 'z')
	{
		p->size = 'z';
		return ((*str)++);
	}
	return (*str);
}
