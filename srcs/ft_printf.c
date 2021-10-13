/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:40 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/13 04:25:01 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	static t_printf	tab;
	static char		tab_constructed;
	int				i;
	int				ret;

	if (!tab_constructed)
		t_printf_constructor(&tab);
	va_start(tab.args, format);
	i = 0;
	ret = 0;
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_eval_format(&tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	ret += tab.tl;
	va_end(tab.args);
	return (ret);
}
