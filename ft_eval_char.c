#include "ft_printf.h"

void	ft_eval_char(t_printf *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	ft_print_char(tab, c);
}

void	ft_print_char(t_printf *tab, char c)
{
	tab->prc = 0;
	tab->hash = 0;
	ft_update_tab(tab, 1);
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, &c, 1);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
