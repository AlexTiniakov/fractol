/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 22:10:20 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/20 22:10:21 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		get_u(va_list *ap, t_p *p, uintmax_t *nbr)
{
	*nbr = va_arg(*ap, uintmax_t);
	if (p->size == 'H')
		*nbr = (unsigned char)*nbr;
	else if (p->size == 'h')
		*nbr = (unsigned short int)*nbr;
	else if (p->size == 'l')
		*nbr = (unsigned long int)*nbr;
	else if (p->size == 'L')
		*nbr = (unsigned long long int)*nbr;
	else if (p->size == 'j')
		*nbr = (uintmax_t)*nbr;
	else if (p->size == 'z')
		*nbr = (size_t)*nbr;
	else
		*nbr = (unsigned int)*nbr;
}

intmax_t	ft_printf_hex(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	get_u(ap, p, &u);
	return (**str == 'X' ? ft_putnbr_unsign(u, _HEXU, p, "0X") :\
							ft_putnbr_unsign(u, _HEXL, p, "0x"));
}
