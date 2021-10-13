/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:08 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/12 22:46:10 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#ifdef __APPLE__

void	ft_eval_percent(t_printf *tab)
{
	ft_update_tab(tab, 1);
	ft_print_nbr_left(tab);
	tab->tl += write(1, "%", 1);
	ft_print_nbr_right(tab);
}

#else

void	ft_eval_percent(t_printf *tab)
{
	tab->tl += write(1, "%", 1);
}

#endif