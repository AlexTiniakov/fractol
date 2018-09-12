/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:42:10 by otiniako          #+#    #+#             */
/*   Updated: 2018/09/12 14:42:11 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define _L system("leaks -q fractol")
# define _PTR fr->mlx_ptr, fr->win_ptr
# include <mlx.h>
# include <math.h>
# include "libft.h"

typedef int 	(*t_f)();

typedef struct	s_fr
{
    int         space : 1;
    char		**av;
    int			ac;
    int         i;
    void        *mlx_ptr;
    void        *win_ptr;
    void        *img_ptr;
    char        *d;
    double      zoom;
    double      moveX;
    double      moveY;
    int         maxIterations;
    int         h;
    int         w;
    int         x;
    int         y;
    double      cRe;
    double      cIm;
    t_f         fractol;
    int         bpp;
    int         sl;
    int         end;
    double pr;
    double pi;
}				t_fr;

int				ft_usage();
t_f				ft_get_fractol(char *str);
void			ft_init_fr(int ac, char **av, t_fr *fr);
int		key_hook(int key, void *param);
int     mouse_hook(int x,int y,void *param);
void    ft_put_pixel(t_fr *fr, int color);
int    mouse_scroll(int button,int x,int y,void *param);

#endif