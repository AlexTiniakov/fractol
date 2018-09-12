/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:24:22 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/21 23:24:23 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_printf_unsigned(char **str, va_list *ap, t_p *p)
{
	uintmax_t u;

	(void)str;
	get_u(ap, p, &u);
	return (ft_putnbr_unsign(u, _DEC, p, NULL));
}
