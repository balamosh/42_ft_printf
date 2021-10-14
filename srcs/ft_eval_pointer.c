/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:21:26 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:25 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_pointer(t_printf *tab)
{
	unsigned long int	nb;

	nb = (unsigned long int) va_arg(tab->args, void *);
	ft_print_pointer(tab, nb);
}

#ifdef __APPLE__

void	ft_print_pointer(t_printf *tab, unsigned long int nb)
{
	tab->hash = 1;
	ft_set_prefix(tab, "0x");
	ft_print_hex(tab, nb, "0123456789abcdef");
}

#else

void	ft_print_pointer(t_printf *tab, unsigned long int nb)
{
	if (nb == 0)
	{
		tab->pnt = 0;
		tab->wdt -= 5;
		ft_print_str(tab, "(nil)");
	}
	else
	{
		tab->hash = 1;
		ft_set_prefix(tab, "0x");
		ft_print_hex(tab, nb, "0123456789abcdef");
	}
}

#endif
