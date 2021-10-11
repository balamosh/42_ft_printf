#include "ft_printf.h"

void	ft_print_nbr_left(t_print *tab)
{
	char	al;

	if (tab->zero)
		tab->tl += ft_print_prefix(tab->prefix);
	if (tab->zero)
		al = '0';
	else
		al = ' ';
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, &al, 1);
	if (!tab->zero)
		tab->tl += ft_print_prefix(tab->prefix);
	while (tab->prc-- > 0)
		tab->tl += write(1, "0", 1);
}

void	ft_print_nbr_right(t_print *tab)
{
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
