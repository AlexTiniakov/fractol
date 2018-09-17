/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:15:40 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/16 13:15:41 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		ft_cyrcle(t_fr *fr, int x, int y, int j)
{
	double i;

	j = 0;
	i = 10000000 / sqrt(sqrt(fr->zoom)) * ((x - fr->w2) * (x - fr->w2) +
	(y - fr->h2) * (y - fr->h2));
	fr->d[(x * 4 + fr->sl * y)] = (int)(x / fr->w2) % 255;
	fr->d[(x * 4 + fr->sl * y) + 1] = (int)(x / fr->w2) % 255;
	fr->d[(x * 4 + fr->sl * y) + 2] = (int)(i / 16);
	return (0);
}

int		ft_mandelbrot3(t_fr *fr, int x, int y, int j)
{
	int			i;
	long double	newre;
	long double	newim;
	long double	oldre;
	long double	oldim;

	fr->pr[x] = fr->tmp1 * 1.2 * (x - fr->w2) + fr->movex;
	fr->pi[y] = 1.2 * (y - fr->h2) / fr->tmp2 + fr->movey;
	newre = 0;
	newim = 0;
	i = -1;
	while (++i < j)
	{
		oldre = newre;
		oldim = newim;
		newre = _F1 - _F2 + _F3;
		newim = _F11 - _F12;
		if ((newre * newre + newim * newim) > 4)
		{
			ft_put_pixel1(x, y, fr, 0xFF * (i ? i : 1) / j);
			break ;
		}
	}
	return (0);
}

int		ft_mandelbrot2(t_fr *fr, int x, int y, int j)
{
	int			i;
	long double	newre;
	long double	newim;
	long double	oldre;
	long double	oldim;

	fr->pr[x] = fr->tmp1 * 1.3 * (x - fr->w2) + fr->movex;
	fr->pi[y] = 1.3 * (y - fr->h2) / fr->tmp2 + fr->movey;
	newre = 0;
	newim = 0;
	i = -1;
	while (++i < j)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre * oldre - 3 * oldim * oldim * oldre + fr->pr[x];
		newim = 3 * oldre * oldre * oldim - oldim * oldim * oldim + fr->pi[y];
		if ((newre * newre + newim * newim) > 4)
		{
			ft_put_pixel1(x, y, fr, 0xFF * (i ? i : 1) / j);
			break ;
		}
	}
	return (0);
}

int		ft_mandelbrot1(t_fr *fr, int x, int y, int j)
{
	int			i;
	long double	newre;
	long double	newim;
	long double	oldre;
	long double	oldim;

	fr->pr[x] = fr->tmp1 * (x - fr->w2) + fr->movex - 0.5;
	fr->pi[y] = (y - fr->h2) / fr->tmp2 + fr->movey;
	newre = 0;
	newim = 0;
	i = -1;
	while (++i < j)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + fr->pr[x];
		newim = 2 * oldre * oldim + fr->pi[y];
		if ((newre * newre + newim * newim) > 4)
		{
			ft_put_pixel1(x, y, fr, 0xFF * (i ? i : 1) / j);
			break ;
		}
	}
	return (0);
}

int		ft_julia1(t_fr *fr, int x, int y, int j)
{
	int			i;
	long double	newre;
	long double	newim;
	long double	oldre;
	long double	oldim;

	newre = fr->tmp1 * (x - fr->w2) + fr->movex;
	newim = (y - fr->h2) / fr->tmp2 + fr->movey;
	i = -1;
	while (++i < j)
	{
		oldre = newre;
		oldim = newim;
		newre = oldre * oldre - oldim * oldim + fr->cre;
		newim = 2 * oldre * oldim + fr->cim;
		if ((newre * newre + newim * newim) > 4)
		{
			ft_put_pixel1(x, y, fr, 0xFF * (i ? i : 1) / j);
			break ;
		}
	}
	return (0);
}
