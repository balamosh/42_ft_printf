/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:09:06 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:42 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_prefix(t_printf *tab, const char *prefix)
{
	int	i;

	i = 0;
	while (prefix[i] != '\0')
	{
		tab->prefix[i] = prefix[i];
		++i;
		--tab->wdt;
	}
	tab->prefix[i] = '\0';
}

void	ft_update_prefix(t_printf *tab)
{
	if (tab->sign)
		ft_set_prefix(tab, "-");
	else if (tab->plus)
		ft_set_prefix(tab, "+");
	else if (tab->sp)
		ft_set_prefix(tab, " ");
}

void	ft_update_tab(t_printf *tab, int len)
{
	ft_update_prefix(tab);
	if (tab->pnt)
		tab->zero = 0;
	if (tab->wdt <= tab->prc || tab->wdt <= len)
		tab->wdt = 0;
	else if (tab->prc > len)
		tab->wdt -= tab->prc;
	else
		tab->wdt -= len;
	if (tab->prc <= len)
		tab->prc = 0;
	else
		tab->prc -= len;
}
