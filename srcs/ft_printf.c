/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:40 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:04:43 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	static t_printf	tab;
	static char		tab_is_constructed;
	int				i;

	if (!tab_is_constructed)
	{
		t_printf_constructor(&tab);
		tab_is_constructed = 1;
	}
	ft_init_tab(&tab);
	va_start(tab.args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_eval_format(&tab, format, i + 1);
		else
			tab.tl += write(1, &format[i], 1);
		++i;
	}
	va_end(tab.args);
	return (tab.tl);
}
