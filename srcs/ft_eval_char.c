/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:13 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:09 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_char(t_printf *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	ft_print_char(tab, c);
}

void	ft_print_char(t_printf *tab, char c)
{
	tab->prc = 0;
	tab->hash = 0;
	ft_update_tab(tab, 1);
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, &c, 1);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
