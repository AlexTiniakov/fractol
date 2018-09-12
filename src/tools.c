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

int    mouse_scroll(int button,int x,int y,void *param)
{
    t_fr *fr;

    fr = (t_fr *)param;
    if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && button == 4)
    {
        fr->zoom += 0.2;
        fr->moveX -= (1/fr->h) * (fr->h / 2 - x)/*1 / 100 * (fr->h / 2 - x)*/;
        fr->moveY -= (1/fr->w) * (fr->w / 2 - y)/*1 / 100 * (fr->w / 2 - y)*/;
        fr->maxIterations *= 1.21;
    }
    else if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && button == 5)
    {
        fr->moveX += fr->zoom > 1 ? (1/fr->h) * (fr->h / 2 - x)/*1 / 100 * (fr->h / 2 - x)*/ : 0;
        fr->moveY += fr->zoom > 1 ? (1/fr->w) * (fr->w / 2 - y)/*1 / 100 * (fr->w / 2 - y)*/ : 0;
        fr->zoom -= fr->zoom > 1 ? 0.2 : 0;
        fr->maxIterations /= fr->maxIterations > 300 ? 1.21 : 1;
    }
    fr->fractol(fr);
    return (0);
}

void    ft_put_pixel(t_fr *fr, int color)
{
    fr->d[(fr->x * 4 + fr->sl * fr->y)] = (color % 255);
    fr->d[(fr->x * 4 + fr->sl * fr->y) + 1] = ((color / 256) % 255);
    fr->d[(fr->x * 4 + fr->sl * fr->y) + 2] = (color / 256 / 256);
}

int     mouse_hook(int x, int y, void *param)
{
    t_fr *fr;

    fr = (t_fr *)param;
    if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && !fr->space)
    {
        fr->cRe = sin(6.28 / 720 * (x));
        fr->cIm = _ABS(cos(6.28 / 720 * (y))) / 3;
        fr->fractol(fr);
    }
    return (0);
}

int		key_hook(int key, void *param)
{
	t_fr *fr;

	fr = (t_fr *)param;
	if (key == 53)
		exit(_L);
    if (key == 49 && !fr->space)
        fr->space = 1;
    else if (key == 49 && fr->space)
        fr->space = 0;
	return (0);
}

int		ft_usage(t_fr *fr)
{
    (void)fr;
    ft_printf("usage: ./fractol [fractals]\n  fractals:\n  --> Mandelbrot\n%s",
    "  --> Julia\n  --> Turtle\n  --> Island\n");
    exit(_L);
    return (0);
}

void	ft_init_fr(int ac, char **av, t_fr *fr)
{
    fr->space = 0;
	fr->ac = ac;
    fr->av = av;
    fr->i = 0;
    fr->mlx_ptr = NULL;
    fr->win_ptr = NULL;
    fr->img_ptr = NULL;
    fr->zoom = 1;
    fr->moveX = 0;
    fr->moveY = 0;
    fr->maxIterations = 300;
    fr->h = 800;
    fr->w = 1000;
	fr->cRe = -0.7;
  	fr->cIm = 0.27015;
    fr->d = NULL;
    fr->bpp = 3;
    fr->sl = fr->w;
    fr->end = 1;
}