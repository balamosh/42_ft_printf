/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:22 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/12 22:46:23 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_eval_hex_low(t_printf *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0)
		tab->hash = 0;
	if (tab->hash)
		ft_strcpy(tab->prefix, "0x");
	ft_print_hex(tab, nb, "0123456789abcdef");
}

void	ft_eval_hex_cap(t_printf *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0)
		tab->hash = 0;
	if (tab->hash)
		ft_strcpy(tab->prefix, "0X");
	ft_print_hex(tab, nb, "0123456789ABCDEF");
}

void	ft_print_hex(t_printf *tab, unsigned long int nb, const char *base)
{
	int	len;

	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		ft_print_empty(tab);
	else
	{
		len = ft_numlen(nb, 16);
		ft_update_tab(tab, len);
		ft_print_nbr_left(tab);
		ft_putnbr_hex(nb, base);
		tab->tl += len;
		ft_print_nbr_right(tab);
	}
}
