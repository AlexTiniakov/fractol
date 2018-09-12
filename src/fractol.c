/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:41:53 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/12 14:41:54 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int ft_get_colour(int i, int maxIterations)
{
	int colour;

	if (!(maxIterations - i))
		return (0);
	colour = 0x0 + 0xFF & (0xFFFFFF / (maxIterations - i));
	return (colour);
}

int	ft_Mandelbrot(t_fr *fr)
{
  double newRe, newIm, oldRe, oldIm;
  int color;
	fr->y = -1;
	int i;
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, fr->w, fr->h);
	fr->d = mlx_get_data_addr(fr->img_ptr, &fr->bpp, &fr->sl, &fr->end);
	while (++fr->y < fr->h)
	{
		fr->x = -1;
		while (++fr->x < fr->w)
		{
			fr->pr = 1.5 * (fr->x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->moveX - 0.5;
    		fr->pi = (fr->y - fr->h / 2) / (0.5 * fr->zoom * fr->h) + fr->moveY;
			newRe = newIm = oldRe = oldIm = 0;
			i = -1;
			while (++i < fr->maxIterations)
			{
				oldRe = newRe;
     			oldIm = newIm;
				newRe = oldRe * oldRe - oldIm * oldIm + fr->pr;
    			newIm = 2 * oldRe * oldIm + fr->pi;
				if((newRe * newRe + newIm * newIm) > 4)
					break;
			}
			color = ft_get_colour(i, fr->maxIterations);
			//mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			ft_put_pixel(fr, color);
		}
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
	return (0);
}

int	ft_Julia(t_fr *fr)
{
       //real and imaginary part of the constant c, determinate shape of the Julia Set
  	double newRe, newIm, oldRe, oldIm;
	int color;
	fr->y = -1;
	int i;
	//mlx_destroy_image(fr->mlx_ptr, fr->img_ptr);
	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, fr->w, fr->h);
	fr->d = mlx_get_data_addr(fr->img_ptr, &fr->bpp, &fr->sl, &fr->end);
	while (++fr->y < fr->h)
	{
		fr->x = -1;
		while (++fr->x < fr->w)
		{
			newRe = 1.5 * (fr->x - fr->w / 2) / (0.5 * fr->zoom * fr->w) + fr->moveX;
    		newIm = (fr->y - fr->h / 2) / (0.5 * fr->zoom * fr->h) + fr->moveY;
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
			color = ft_get_colour(i, fr->maxIterations);
			//mlx_pixel_put(fr->mlx_ptr, fr->win_ptr, fr->x, fr->y, color);
			ft_put_pixel(fr, color);
		}
	}
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
	return (0);
}

t_f		ft_get_fractol(char *str)
{
	if (!ft_strcmp(str, "Mandelbrot"))
		return (ft_Mandelbrot);
	if (!ft_strcmp(str, "Julia"))
		return (ft_Julia);
	return (ft_usage);
}

int		main(int ac, char **av)
{
	t_fr	fr;

	if (ac < 2)
		return (ft_usage(&fr));
	ft_init_fr(ac, av, &fr);
	fr.mlx_ptr = mlx_init();
	fr.win_ptr = mlx_new_window(fr.mlx_ptr, 1000, 800, "Fractol");
	(fr.fractol = ft_get_fractol(*(++av)))(&fr);
	mlx_mouse_hook(fr.win_ptr, mouse_scroll, (void *)&fr);
	mlx_hook(fr.win_ptr, 6, 1L << 6, mouse_hook, (void *)&fr);
	mlx_key_hook(fr.win_ptr, key_hook, (void *)&fr);
	mlx_loop(fr.mlx_ptr);
	return (0);
}
