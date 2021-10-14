/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:30 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:28 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef __APPLE__

void	ft_eval_str(t_printf *tab)
{
	char	*str;

	if (tab->plus && tab->sp)
		++tab->wdt;
	str = va_arg(tab->args, char *);
	ft_print_str(tab, str);
}

#else

void	ft_eval_str(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	ft_print_str(tab, str);
}

#endif

void	ft_print_str(t_printf *tab, const char *str)
{
	int	len;

	if (!str)
		str = ft_set_null(tab, "(null)");
	len = ft_strlen(str);
	if (tab->pnt)
	{
		len = ft_min(len, tab->prc);
		tab->prc = 0;
	}
	tab->hash = 0;
	tab->sp = 0;
	ft_update_tab(tab, len);
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, str, len);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
