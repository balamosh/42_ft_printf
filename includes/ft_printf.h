/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:43 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 23:07:27 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct s_printf
{
	va_list		args;
	int			wdt;
	int			prc;
	int			zero;
	int			pnt;
	int			dash;
	int			sign;
	int			sp;
	int			hash;
	int			plus;
	int			tl;
	char		prefix[3];
	int			cnv_hash[256];
	int			flg_hash[256];
	void		(*cnv_eval[9])(struct s_printf *);
	int			(*flg_eval[7])(struct s_printf *, const char *, int);
}				t_printf;

/*
**	ft_printf main functions
*/

int		ft_printf(const char *format, ...);
int		ft_eval_format(t_printf *tab, const char *format, int pos);

/*
**	Conversion evaluation functions
*/

void	ft_eval_char(t_printf *tab);
void	ft_print_char(t_printf *tab, char c);

void	ft_eval_str(t_printf *tab);
void	ft_print_str(t_printf *tab, const char *str);

void	ft_eval_int(t_printf *tab);
void	ft_print_int(t_printf *tab, int nb);

void	ft_eval_unsigned_int(t_printf *tab);
void	ft_print_unsigned_int(t_printf *tab, unsigned int nb);
void	ft_putnbr_un(unsigned int nb);

void	ft_eval_hex_low(t_printf *tab);
void	ft_eval_hex_cap(t_printf *tab);
void	ft_print_hex(t_printf *tab, unsigned long int nb, const char *base);
void	ft_putnbr_hex(unsigned long int nb, const char *base);

void	ft_eval_pointer(t_printf *tab);
void	ft_print_pointer(t_printf *tab, unsigned long int nb);

void	ft_eval_percent(t_printf *tab);

/*
**	Conversion evaluation utility functions
*/

int		ft_print_prefix(const char *prefix);
void	ft_print_empty(t_printf *tab);
char	*ft_set_null(t_printf *tab, const char *str);
void	ft_print_nbr_left(t_printf *tab);
void	ft_print_nbr_right(t_printf *tab);

/*
**	Flag evaluation functions
*/

int		ft_eval_width(t_printf *tab, const char *format, int pos);
int		ft_flag_dash(t_printf *tab, const char *format, int pos);
int		ft_flag_zero(t_printf *tab, const char *format, int pos);
int		ft_flag_point(t_printf *tab, const char *format, int pos);
int		ft_flag_star(t_printf *tab, const char *format, int pos);
int		ft_flag_hash(t_printf *tab, const char *format, int pos);
int		ft_flag_space(t_printf *tab, const char *format, int pos);
int		ft_flag_plus(t_printf *tab, const char *format, int pos);

/*
**	t_printf tab utility functions
*/

void	ft_reset_tab(t_printf *tab);
void	ft_init_tab(t_printf *tab);
void	t_printf_constructor(t_printf *tab);
void	ft_set_prefix(t_printf *tab, const char *prefix);
void	ft_update_prefix(t_printf *tab);
void	ft_update_tab(t_printf *tab, int len);

/*
**	Libft/utility functions
*/

int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_min(int a, int b);
int		ft_numlen(unsigned long int nb, int base_len);
void	ft_putchar_fd(char c, int fd);

#endif
