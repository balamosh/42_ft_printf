/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flags_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:09:35 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:12 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_eval_width(t_printf *tab, const char *format, int pos)
{
	int	len;

	tab->wdt = ft_atoi(format + pos);
	len = ft_numlen(tab->wdt, 10);
	return (pos + len);
}

int	ft_flag_dash(t_printf *tab, const char *format, int pos)
{
	(void) format;
	tab->dash = 1;
	return (++pos);
}

int	ft_flag_zero(t_printf *tab, const char *format, int pos)
{
	(void) format;
	tab->zero = 1;
	return (++pos);
}

int	ft_flag_point(t_printf *tab, const char *format, int pos)
{
	tab->pnt = 1;
	++pos;
	if (ft_isdigit(format[pos]))
	{
		tab->prc = ft_atoi(format + pos);
		while (ft_isdigit(format[pos]))
			++pos;
	}
	return (pos);
}
