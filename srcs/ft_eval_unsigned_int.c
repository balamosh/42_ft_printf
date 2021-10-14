/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_unsigned_int.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:34 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:47:27 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_unsigned_int(t_printf *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		ft_print_empty(tab);
	else
		ft_print_unsigned_int(tab, nb);
}

void	ft_print_unsigned_int(t_printf *tab, unsigned int nb)
{
	int	len;

	len = ft_numlen(nb, 10);
	tab->hash = 0;
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	ft_putnbr_un(nb);
	tab->tl += len;
	ft_print_nbr_right(tab);
}
