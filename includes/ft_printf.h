/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:43 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/13 04:05:37 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
	va_list		args;
	int			wdt;
	int			prc;
	int			zero;
	int			pnt;
	int			dash;
	int			tl;
	int			sign;
	int			sp;
	int			hash;
	int			plus;
	char		prefix[3];
	char		cnv_list[10];
	char		flg_list[8];
	int			cnv_hash[256];
	int			flg_hash[256];
	void		(*cnv_eval[9])(struct s_printf *);
	int			(*flg_eval[7])(struct s_printf *, const char *, int);
}		t_printf;

/*
**	ft_printf function
*/

int	ft_printf(const char *format, ...);

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
void	ft_eval_pointer(t_printf *tab);
void	ft_print_pointer(t_printf *tab, unsigned long int nb);
void	ft_eval_percent(t_printf *tab);

/*
**	Conversion evaluation utility functions
*/

void	ft_print_empty(t_printf *tab);
char	*ft_set_null(t_printf *tab, const char *str);

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
void	ft_update_prefix(t_printf *tab);
void	ft_update_tab(t_printf *tab, int len);

#endif
