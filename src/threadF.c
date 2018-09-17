/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:44:12 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/13 14:44:12 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_usage(t_fr *fr)
{
	(void)fr;
	ft_printf("usage: ./fractol [fractals]\n  fractals:\n  --> Julia\n%s",
	"  --> Mandelbrot\n  --> Mandelbrot3\n  --> Mandelbrot4\n  --> Cyrcle\n");
	ft_printf("tools:\ncolors: 1-3 r g b\nzoom: + -\npause: ' ' z\n");
	return (0);
}

void	*threadfunc1(void *thread_data)
{
	t_fr *fr;

	fr = (t_fr *)thread_data;
	fr->y1 = -1;
	while (++fr->y1 <= fr->h2)
	{
		fr->x1 = -1;
		while (++fr->x1 <= fr->w2)
			fr->fractol1(fr, fr->x1, fr->y1, fr->maxiterations);
	}
	return (thread_data);
}

void	*threadfunc2(void *thread_data)
{
	t_fr *fr;

	fr = (t_fr *)thread_data;
	fr->y2 = fr->h2;
	while (++fr->y2 < fr->h)
	{
		fr->x2 = -1;
		while (++fr->x2 <= fr->w2)
			fr->fractol1(fr, fr->x2, fr->y2, fr->maxiterations);
	}
	return (thread_data);
}

void	*threadfunc3(void *thread_data)
{
	t_fr *fr;

	fr = (t_fr *)thread_data;
	fr->y3 = -1;
	while (++fr->y3 <= fr->h2)
	{
		fr->x3 = fr->w2;
		while (++fr->x3 < fr->w)
			fr->fractol1(fr, fr->x3, fr->y3, fr->maxiterations);
	}
	return (thread_data);
}

void	*threadfunc4(void *thread_data)
{
	t_fr *fr;

	fr = (t_fr *)thread_data;
	fr->y4 = fr->h2;
	while (++fr->y4 < fr->h)
	{
		fr->x4 = fr->w2;
		while (++fr->x4 < fr->w)
			fr->fractol1(fr, fr->x4, fr->y4, fr->maxiterations);
	}
	return (thread_data);
}
