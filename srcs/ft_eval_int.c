/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:26 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/13 04:23:20 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_eval_int(t_printf *tab)
{
	int		nb;

	nb = va_arg(tab->args, int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		ft_print_empty(tab);
	else
		ft_print_int(tab, nb);
}

void	ft_print_int(t_printf *tab, int nb)
{
	int		i;
	int		len;
	char	*nbr;

	if (nb < 0)
		tab->sign = 1;
	if (tab->pnt)
		tab->zero = 0;
	nbr = ft_itoa(nb);
	if (!nbr)
		return ;
	len = ft_strlen(nbr) - tab->sign;
	tab->hash = 0;
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	i = tab->sign;
	while (nbr[i])
		tab->tl += write(1, &nbr[i++], 1);
	free(nbr);
	ft_print_nbr_right(tab);
}
