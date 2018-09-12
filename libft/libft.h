/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiniako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:22:04 by otiniako          #+#    #+#             */
/*   Updated: 2018/03/26 22:44:27 by otiniako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 100000
# define _MIN(a, b) a < b ? a : b
# define _MAX(a, b) a > b ? a : b
# define _SCR1 p->size == 'H' || p->size == 'h'
# define _SCR2 p->size == 'H' || p->size == 'h' || p->size == 'l'
# define _ABS(x) x < 0 ? -x : x
# define _NEGATIVE(x) x < 0 ? 1 : 0
# define _DEC "0123456789"
# define _OCT "01234567"
# define _HEXU "0123456789ABCDEF"
# define _HEXL "0123456789abcdef"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <fcntl.h>
# include <errno.h>

typedef struct		s_p
{
	int				reshetka : 1;
	int				zero : 1;
	int				minus : 1;
	int				plus : 1;
	int				probel : 1;
	int				is_width : 1;
	int				is_precision : 1;
	int				width;
	int				precision;
	char			size;
}					t_p;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *restrict dst, const void *restrict src,\
								size_t n);
void				*ft_memccpy(void *restrict dst, const void *restrict src,\
								int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
char				*ft_strncat(char *restrict s1, const char *restrict s2,\
								size_t n);
size_t				ft_strlcat(char *restrict dst, const char *restrict src,\
								size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,\
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(intmax_t nbr);
void				ft_putnbr_u_base_fd(uintmax_t nbr, char *base, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(intmax_t nbr, int fd);
void				ft_strrev(char *str);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_strjoin_clean(char *s1, char *s2);
size_t				ft_wstrlen(wchar_t *s);
wchar_t				*ft_wstrnew(size_t size);
void				ft_putnwstr(const wchar_t *str, size_t len);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwchar(wchar_t chr);
void				ft_putnstr(char const *s, int n);
void				ft_putnbr_base(intmax_t nbr, char *base);
int64_t				ft_atoi_base(char *str, char *base);
void				ft_putnbr_u(uintmax_t nbr);
int					ft_printf(const char *format, ...);
intmax_t			ft_atoi_long(const char *str);
char				*ft_str_toupper(char *str);

char				*ft_check_flags(char **str, t_p *p);
char				*ft_check_width(char **str, t_p *p, va_list *ap);
char				*ft_check_precision(char **str, t_p *p, va_list *ap,\
										int pr);
char				*ft_check_size(char **str, t_p *p, char c);

int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				ft_probels(int len, int width, char c);
uintmax_t			ft_len(uintmax_t j, char *base);
uintmax_t			ft_len_j(uintmax_t j, char *base, char *front, t_p *p);
void				get_u(va_list *ap, t_p *p, uintmax_t *nbr);

intmax_t			ft_null(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_procent(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_int(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_long(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_char(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_wchar(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_str(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_wstr(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_hex(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_octal(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_unsigned(char **str, va_list *ap, t_p *p);
intmax_t			ft_printf_void(char **str, va_list *ap, t_p *p);

typedef intmax_t	(*t_fun)(char**, va_list*, t_p*);
t_fun				ft_get_fun(char c);

intmax_t			ft_putnbr_front(uintmax_t j, char *base, t_p *p,\
									char front);
intmax_t			ft_putnbr_unsign(uintmax_t j, char *base, t_p *p,\
										char *front);
int					get_next_line(int const fd, char **line);
uintmax_t			ft_atoi_uint(const char *str);

#endif
