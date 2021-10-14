/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_conv_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:09:13 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 15:13:55 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_prefix(const char *prefix)
{
	int	i;

	i = 0;
	while (prefix[i])
		write(1, &prefix[i++], 1);
	return (i);
}

void	ft_print_empty(t_printf *tab)
{
	ft_update_prefix(tab);
	tab->tl += ft_print_prefix(tab->prefix);
	while (tab->wdt-- > 0)
		tab->tl += write(1, " ", 1);
}

#ifdef __APPLE__

char	*ft_set_null(t_printf *tab, const char *str)
{
	(void) tab;
	return ((char *) str);
}

#else

char	*ft_set_null(t_printf *tab, const char *str)
{
	if (tab->pnt && tab->prc < 6)
		tab->prc = 0;
	return ((char *) str);
}

#endif