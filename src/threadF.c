/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threadF.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:44:12 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/13 14:44:12 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int ft_get_colour1(int i, int maxIterations, t_fr *fr)//try all like this one
{
	int colour;

	colour = fr->col / i;
	return (colour);
}

int ft_get_colour2(int i, int maxIterations, t_fr *fr)
{
	int colour;

	if (!(maxIterations - i))
		return (0);
	colour = fr->col & (0xFFFFFF / (maxIterations - i));
	return (colour);
}

int ft_get_colour3(int i, int maxIterations, t_fr *fr)
{
	int colour;

	if (!(maxIterations - i))
		return (0);
	colour = fr->col & (0xFFFFFF / (maxIterations - i));
	return (colour);
}

int ft_get_colour4(int i, int maxIterations, t_fr *fr)
{
	int colour;

	if (!(maxIterations - i))
		return (0);
	colour = fr->col & (0xFFFFFF / (maxIterations - i));
	return (colour);
}

void* threadFunc1(void* thread_data)//optimize all like this one
{
    t_fr *fr = (t_fr *)thread_data;
    int i;
    long double newRe, newIm, oldRe, oldIm;
    int x;
    int y = -1;
	int tab1 = fr->zoom * fr->w2 / 1.5;//to fr
	int tab2 = fr->zoom * fr->w2;//to fr
    while (++y <= fr->h2)
	{
		x = -1;
		while (++x <= fr->w2)
		{
			newRe = (x - fr->w2) / fr->tab1 + fr->moveX;
    		newIm = (y - fr->h2) / fr->tab2 + fr->moveY;
			i = -1;
			while (++i < fr->maxIterations)
			{
				oldRe = newRe;
     			oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + fr->cRe;
      			newIm = 2 * oldRe * oldIm + fr->cIm;
				if((newRe * newRe + newIm * newIm) > 4)
				{
					ft_put_pixel1(x, y, fr, ft_get_colour1(i, fr->maxIterations, fr));
					break;
				}
			}
		}
	}
    //ft_printf("1\n");
    return (thread_data);
}

void* threadFunc2(void* thread_data)
{
    t_fr *fr = (t_fr *)thread_data;
    int i;
    int color;
    long double newRe, newIm, oldRe, oldIm;
    int x;
    int y = fr->h / 2;
    while (++y < fr->h)
	{
		x = -1;
		while (++x <= fr->w / 2)
		{
			newRe = 1.5 * (x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->moveX;
    		newIm = (y - fr->h / 2) / (0.5 * fr->zoom * fr->h) + fr->moveY;
			i = -1;
			while (++i < fr->maxIterations)
			{
				oldRe = newRe;
     			oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + fr->cRe;
      			newIm = 2 * oldRe * oldIm + fr->cIm;
				if((newRe * newRe + newIm * newIm) > 4)
					break;
			}
            if (i != fr->maxIterations)
            {
			color = ft_get_colour2(i, fr->maxIterations, fr);
			//mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, fr->x, fr->y, color);
			ft_put_pixel1(x, y, fr, color);
            }
		}
	}
    //ft_printf("2\n");
    return (thread_data);
}

void* threadFunc3(void* thread_data)
{
    t_fr *fr = (t_fr *)thread_data;
    int i;
    int color;
    long double newRe, newIm, oldRe, oldIm;
    int x;
    int y = -1;
    while (++y <= fr->h / 2)
	{
		x = fr->w / 2;
		while (++x < fr->w)
		{
			newRe = 1.5 * (x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->moveX;
    		newIm = (y - fr->h / 2) / (0.5 * fr->zoom * fr->h) + fr->moveY;
			i = -1;
			while (++i < fr->maxIterations)
			{
				oldRe = newRe;
     			oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + fr->cRe;
      			newIm = 2 * oldRe * oldIm + fr->cIm;
				if((newRe * newRe + newIm * newIm) > 4)
					break;
			}
            if (i != fr->maxIterations)
            {
			color = ft_get_colour3(i, fr->maxIterations, fr);
			//mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, fr->x, fr->y, color);
			ft_put_pixel1(x, y, fr, color);
            }
		}
	}
    //ft_printf("3\n");
    return (thread_data);
}

void* threadFunc4(void* thread_data)
{
    t_fr *fr = (t_fr *)thread_data;
    int i;
    int color;
    long double newRe, newIm, oldRe, oldIm;
    int x;
    int y = fr->h / 2;
    while (++y < fr->h)
	{
		x = fr->w / 2;
		while (++x < fr->w)
		{
			newRe = 1.5 * (x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->moveX;
    		newIm = (y - fr->h / 2) / (0.5 * fr->zoom * fr->h) + fr->moveY;
			i = -1;
			while (++i < fr->maxIterations)
			{
				oldRe = newRe;
     			oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + fr->cRe;
      			newIm = 2 * oldRe * oldIm + fr->cIm;
				if((newRe * newRe + newIm * newIm) > 4)
					break;
			}
            if (i != fr->maxIterations)
            {
			 color = ft_get_colour4(i, fr->maxIterations, fr);
			 //mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, fr->x, fr->y, color);
			 ft_put_pixel1(x, y, fr, color);
            }
		}
	}
    //ft_printf("4\n");
    return (thread_data);
}