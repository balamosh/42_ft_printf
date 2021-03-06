/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_flags_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:09:27 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:45:14 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_hash(t_printf *tab, const char *format, int pos)
{
	(void) format;
	tab->hash = 1;
	return (++pos);
}

int	ft_flag_space(t_printf *tab, const char *format, int pos)
{
	(void) format;
	tab->sp = 1;
	return (++pos);
}

int	ft_flag_plus(t_printf *tab, const char *format, int pos)
{
	(void) format;
	tab->plus = 1;
	return (++pos);
}
