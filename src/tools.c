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
        fr->zoom += (fr->zoom / 10);
        fr->moveX -= (fr->w / 2 - x) / (fr->zoom * fr->w * 2);
        fr->moveY -= (fr->h / 2 - y) / (fr->zoom * fr->h * 2);
    }
    else if (x >= 0 && y >= 0 && x <= fr->w && y <= fr->h && button == 5 && fr->zoom > 1)
    {
        fr->moveX -= (fr->w / 2 - x) / (fr->zoom * fr->w * 2);
        fr->moveY -= (fr->h / 2 - y) / (fr->zoom * fr->h * 2);
        fr->zoom -= (fr->zoom / 10);
    }
    //printf("%f, %f, %f\n", fr->moveX, fr->moveY, fr->zoom);
    fr->fractol(fr);
    return (0);
}

void    ft_put_pixel(t_fr *fr, int color)
{
    fr->d[(fr->x * 4 + fr->sl * fr->y)] = (color % 255);
    fr->d[(fr->x * 4 + fr->sl * fr->y) + 1] = ((color / 256) % 255);
    fr->d[(fr->x * 4 + fr->sl * fr->y) + 2] = (color / 256 / 256);
}

void    ft_put_pixel1(int x, int y, t_fr *fr, int color)
{
    fr->d[(x * 4 + fr->sl * y)] = (color % 255);
    fr->d[(x * 4 + fr->sl * y) + 1] = ((color / 256) % 255);
    fr->d[(x * 4 + fr->sl * y) + 2] = (color / 256 / 256);
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
		exit(0);
    if (key == 49 && !fr->space)
        fr->space = 1;
    else if (key == 6 && fr->space)
        fr->space = 0;
    if (key == 69)
    {
        fr->maxIterations += 1;
        fr->fractol(fr);
    }
    else if (key == 78)
    {
        fr->maxIterations -= fr->maxIterations > 30 ? 1 : 0;
        fr->fractol(fr);
    }
    if ((key >= 18 && key <= 20) || key == 15 || key == 5 || key == 11)
    {
        fr->col = key == 18 ? 0xFFFF00 : fr->col;
        fr->col = key == 19 ? 0xFF00FF : fr->col;
        fr->col = key == 20 ? 0x00FFFF : fr->col;
        fr->col = key == 15 ? 0xFF0000 : fr->col;
        fr->col = key == 5 ? 0x00FF00 : fr->col;
        fr->col = key == 11 ? 0x0000FF : fr->col;
        fr->fractol(fr);
    }
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
    fr->maxIterations = 30;
    fr->h = 800;
    fr->w = 1000;
	fr->h2 = 400;
	fr->w2 = 500;
	fr->cRe = -0.7;
  	fr->cIm = 0.27015;
    fr->d = NULL;
    fr->bpp = 3;
    fr->sl = fr->w;
    fr->end = 1;
    fr->col = 0xFFFFFF;
}