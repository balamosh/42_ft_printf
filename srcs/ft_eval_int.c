/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:26 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:47:14 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_int(t_printf *tab)
{
	int		nb;

	nb = va_arg(tab->args, int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
	{
		if (tab->plus)
		{
			++tab->wdt;
			ft_print_char(tab, '+');
		}
		else
			ft_print_empty(tab);
	}
	else
		ft_print_int(tab, nb);
}

void	ft_print_int(t_printf *tab, int nb)
{
	int			len;
	long int	nbr;

	nbr = nb;
	if (nbr < 0)
	{
		tab->sign = 1;
		nbr = -nbr;
	}
	if (tab->pnt)
		tab->zero = 0;
	len = ft_numlen(nbr, 10);
	tab->hash = 0;
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	ft_putnbr_un(nbr);
	tab->tl += len;
	ft_print_nbr_right(tab);
}
