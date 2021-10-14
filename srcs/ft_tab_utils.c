/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:47 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 16:20:38 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_tab(t_printf *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->sign = 0;
	tab->sp = 0;
	tab->hash = 0;
	tab->plus = 0;
	tab->prefix[0] = '\0';
}

void	ft_init_tab(t_printf *tab)
{
	ft_reset_tab(tab);
	tab->tl = 0;
}

static void	fill_functions_hash(int *hash, const char *str)
{
	int	i;

	i = 0;
	while (i < 256)
		hash[i++] = -1;
	i = 0;
	while (str[i])
	{
		hash[(int) str[i]] = i;
		++i;
	}
}

void	t_printf_constructor(t_printf *tab)
{
	fill_functions_hash(tab->cnv_hash, "cspdiuxX%");
	fill_functions_hash(tab->flg_hash, "-0.*# +");
	tab->cnv_eval[tab->cnv_hash[(int) 'c']] = &ft_eval_char;
	tab->cnv_eval[tab->cnv_hash[(int) 's']] = &ft_eval_str;
	tab->cnv_eval[tab->cnv_hash[(int) 'p']] = &ft_eval_pointer;
	tab->cnv_eval[tab->cnv_hash[(int) 'd']] = &ft_eval_int;
	tab->cnv_eval[tab->cnv_hash[(int) 'i']] = &ft_eval_int;
	tab->cnv_eval[tab->cnv_hash[(int) 'u']] = &ft_eval_unsigned_int;
	tab->cnv_eval[tab->cnv_hash[(int) 'x']] = &ft_eval_hex_low;
	tab->cnv_eval[tab->cnv_hash[(int) 'X']] = &ft_eval_hex_cap;
	tab->cnv_eval[tab->cnv_hash[(int) '%']] = &ft_eval_percent;
	tab->flg_eval[tab->flg_hash[(int) '-']] = &ft_flag_dash;
	tab->flg_eval[tab->flg_hash[(int) '0']] = &ft_flag_zero;
	tab->flg_eval[tab->flg_hash[(int) '.']] = &ft_flag_point;
	tab->flg_eval[tab->flg_hash[(int) '*']] = &ft_flag_star;
	tab->flg_eval[tab->flg_hash[(int) '#']] = &ft_flag_hash;
	tab->flg_eval[tab->flg_hash[(int) ' ']] = &ft_flag_space;
	tab->flg_eval[tab->flg_hash[(int) '+']] = &ft_flag_plus;
}
