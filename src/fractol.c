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

double	ft_abs(double x)
{
	if (x >= 0)
		return (x);
	else
		return (0 - x);
}

int		ft_get_colour(int i, int max_i)
{
	int colour;

	if (!(max_i - i))
		return (0);
	colour = 0x0 + (0xFFFFFF / (max_i - i));
	return (colour);
}

int		ft_fractol(t_fr *fr)
{
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;

	mlx_clear_window(fr->mlx_ptr, fr->win_ptr);
	fr->img_ptr = mlx_new_image(fr->mlx_ptr, fr->w, fr->h);
	fr->d = mlx_get_data_addr(fr->img_ptr, &fr->bpp, &fr->sl, &fr->end);
	pthread_create(&t1, NULL, threadfunc1, (void *)fr);
	pthread_create(&t2, NULL, threadfunc2, (void *)fr);
	pthread_create(&t3, NULL, threadfunc3, (void *)fr);
	pthread_create(&t4, NULL, threadfunc4, (void *)fr);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	mlx_put_image_to_window(fr->mlx_ptr, fr->win_ptr, fr->img_ptr, 0, 0);
	return (0);
}

t_f		ft_get_fractol(char *str, t_fr *fr)
{
	fr->fractol1 = NULL;
	if (!ft_strcmp(str, "Mandelbrot"))
		fr->fractol1 = ft_mandelbrot1;
	if (!ft_strcmp(str, "Julia"))
		fr->fractol1 = ft_julia1;
	if (!ft_strcmp(str, "Mandelbrot3"))
		fr->fractol1 = ft_mandelbrot2;
	if (!ft_strcmp(str, "Mandelbrot4"))
		fr->fractol1 = ft_mandelbrot3;
	if (!ft_strcmp(str, "Cyrcle"))
		fr->fractol1 = ft_cyrcle;
	return (fr->fractol1 ? ft_fractol : ft_usage);
}

int		main(int ac, char **av)
{
	t_fr	fr;

	if (ac < 2)
		return (ft_usage(&fr));
	ft_init_fr(&fr);
	if ((fr.fractol = ft_get_fractol(*(++av), &fr)) == ft_usage)
		return (fr.fractol(&fr));
	fr.mlx_ptr = mlx_init();
	fr.win_ptr = mlx_new_window(fr.mlx_ptr, 1000, 800, "Fractol");
	fr.fractol(&fr);
	mlx_mouse_hook(fr.win_ptr, mouse_scroll, (void *)&fr);
	mlx_hook(fr.win_ptr, 6, 1L << 6, mouse_hook, (void *)&fr);
	mlx_hook(fr.win_ptr, 2, 5, key_hook, (void *)&fr);
	mlx_loop(fr.mlx_ptr);
	return (0);
}
