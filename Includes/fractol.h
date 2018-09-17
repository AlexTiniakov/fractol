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
# define _F1 oldre * oldre * oldre * oldre
# define _F2 6 * oldim * oldim * oldre * oldre
# define _F3 oldim * oldim * oldim * oldim + fr->pr[x]
# define _F11 4 * oldre * oldre * oldre * oldim
# define _F12 4 * oldim * oldim * oldim * oldre + fr->pi[y]
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"

typedef int			(*t_f)();

typedef struct		s_stack
{
	double			movex;
	double			movey;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_fr
{
	int				space : 1;
	int				i;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*d;
	double			zoom;
	double			movex;
	double			movey;
	int				maxiterations;
	int				h;
	int				w;
	int				x;
	int				y;
	double			cre;
	double			cim;
	t_f				fractol;
	t_f				fractol1;
	int				bpp;
	int				sl;
	int				end;
	int				col;
	double			pr[1001];
	double			pi[801];
	int				h2;
	int				w2;
	double			tmp1;
	double			tmp2;
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				x3;
	int				y3;
	int				x4;
	int				y4;
}					t_fr;

int					ft_usage();
t_f					ft_get_fractol(char *str, t_fr *fr);
void				ft_init_fr(t_fr *fr);
int					key_hook(int key, void *param);
int					mouse_hook(int x, int y, void *param);
void				ft_put_pixel(t_fr *fr, int color);
void				ft_put_pixel1(int x, int y, t_fr *fr, int color);
int					mouse_scroll(int button, int x, int y, void *param);
void				*threadfunc1(void *thread_data);
void				*threadfunc2(void *thread_data);
void				*threadfunc3(void *thread_data);
void				*threadfunc4(void *thread_data);
int					ft_get_colour(int i, int maxiterations);
double				ft_abs(double x);
int					ft_julia1(t_fr *fr, int x, int y, int j);
int					ft_mandelbrot1(t_fr *fr, int x, int y, int j);
int					ft_mandelbrot2(t_fr *fr, int x, int y, int j);
int					ft_mandelbrot3(t_fr *fr, int x, int y, int j);
int					ft_cyrcle(t_fr *fr, int x, int y, int j);

#endif
