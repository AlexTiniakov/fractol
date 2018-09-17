/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:47:11 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/12 14:47:11 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_scroll(int button, int x, int y, void *param)
{
	t_fr *fr;

	fr = (t_fr *)param;
	if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && button == 4)
	{
		fr->zoom += (fr->zoom / 10);
		fr->movex -= (fr->w / 2 - x) / (fr->zoom * fr->w * 2);
		fr->movey -= (fr->h / 2 - y) / (fr->zoom * fr->h * 2);
		fr->tmp1 = 1.5 / ((double)fr->zoom * (double)fr->w2);
		fr->tmp2 = (double)(fr->zoom * fr->h2);
	}
	else if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h &&
	button == 5 && fr->zoom > 1)
	{
		fr->movex -= (fr->w / 2 - x) / (fr->zoom * fr->w * 2);
		fr->movey -= (fr->h / 2 - y) / (fr->zoom * fr->h * 2);
		fr->zoom -= (fr->zoom / 10);
		fr->tmp1 = 1.5 / ((double)fr->zoom * (double)fr->w2);
		fr->tmp2 = (double)(fr->zoom * fr->h2);
	}
	fr->fractol(fr);
	return (0);
}

void	ft_put_pixel(t_fr *fr, int color)
{
	fr->d[(fr->x * 4 + fr->sl * fr->y)] = (color % 255);
	fr->d[(fr->x * 4 + fr->sl * fr->y) + 1] = ((color / 256) % 255);
	fr->d[(fr->x * 4 + fr->sl * fr->y) + 2] = (color / 256 / 256);
}

void	ft_put_pixel1(int x, int y, t_fr *fr, int color)
{
	fr->d[(x * 4 + fr->sl * y)] = fr->col % 256 ? color : 0;
	fr->d[(x * 4 + fr->sl * y) + 1] = fr->col / 256 % 256 ? color : 0;
	fr->d[(x * 4 + fr->sl * y) + 2] = fr->col / 256 / 256 ? color : 0;
}

int		mouse_hook(int x, int y, void *param)
{
	t_fr *fr;

	fr = (t_fr *)param;
	if (fr->fractol1 == ft_julia1
	&& x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && !fr->space)
	{
		fr->cre = sin(6.28 / 720 * (x));
		fr->cim = _ABS(cos(6.28 / 720 * (y))) / 3;
		fr->fractol(fr);
	}
	return (0);
}

int		key_hook(int key, void *param)
{
	t_fr *fr;

	fr = (t_fr *)param;
	if (key == 53)
		exit(0);
	else if (key == 49 && !fr->space)
		fr->space = 1;
	else if (key == 6 && fr->space)
		fr->space = 0;
	else if (key == 69 && fr->maxiterations < 2147483647)
		fr->maxiterations += 1;
	else if (key == 78)
		fr->maxiterations -= fr->maxiterations > 30 ? 1 : 0;
	else if ((key >= 18 && key <= 20) || key == 15 || key == 5 || key == 11)
	{
		fr->col = key == 18 ? 0xFFFF00 : fr->col;
		fr->col = key == 19 ? 0xFF00FF : fr->col;
		fr->col = key == 20 ? 0x00FFFF : fr->col;
		fr->col = key == 15 ? 0xFF0000 : fr->col;
		fr->col = key == 5 ? 0x00FF00 : fr->col;
		fr->col = key == 11 ? 0x0000FF : fr->col;
	}
	return (fr->fractol(fr));
}
