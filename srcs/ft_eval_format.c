/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:17 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:15 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_eval_flag(t_printf *tab, const char *format, int pos)
{
	int	f_id;

	f_id = tab->flg_hash[(int) format[pos]];
	if (f_id != -1)
		pos = tab->flg_eval[f_id](tab, format, pos);
	else if (ft_isdigit(format[pos]))
		pos = ft_eval_width(tab, format, pos);
	else
		++pos;
	return (pos);
}

int	ft_eval_format(t_printf *tab, const char *format, int pos)
{
	int	c_id;

	c_id = tab->cnv_hash[(int) format[pos]];
	while (c_id == -1)
	{
		if (!format[pos])
			return (pos - 1);
		pos = ft_eval_flag(tab, format, pos);
		c_id = tab->cnv_hash[(int) format[pos]];
	}
	tab->cnv_eval[c_id](tab);
	ft_reset_tab(tab);
	return (pos);
}
