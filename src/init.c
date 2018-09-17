/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 16:25:06 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/16 16:25:07 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ft_init_fr(t_fr *fr)
{
	fr->space = 0;
	fr->i = 0;
	fr->mlx_ptr = NULL;
	fr->win_ptr = NULL;
	fr->img_ptr = NULL;
	fr->zoom = 1;
	fr->movex = 0;
	fr->movey = 0;
	fr->maxiterations = 30;
	fr->h = 800;
	fr->w = 1000;
	fr->cre = -0.7;
	fr->cim = 0.27015;
	fr->d = NULL;
	fr->bpp = 3;
	fr->sl = fr->w;
	fr->end = 1;
	fr->col = 0xFFFFFF;
	fr->w2 = fr->w / 2;
	fr->h2 = fr->h / 2;
	fr->tmp1 = 1.5 / ((double)fr->zoom * (double)fr->w2);
	fr->tmp2 = (double)(fr->zoom * fr->h2);
}
