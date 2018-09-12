/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_procent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:25:56 by otiniako          #+#    #+#             */
/*   Updated: 2018/05/11 12:25:57 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_printf_procent(char **str, va_list *ap, t_p *p)
{
	(void)str;
	(void)ap;
	if (p->is_width && !p->minus)
		ft_probels(1, p->width, p->zero ? '0' : ' ');
	write(1, "%", 1);
	if (p->is_width && p->minus)
		ft_probels(1, p->width, ' ');
	return (p->is_width ? ft_max(p->width, 1) : 1);
}
