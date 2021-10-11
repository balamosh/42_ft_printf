#include "ft_printf.h"
#include "libft.h"

void	ft_eval_str(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	ft_print_str(tab, str);
}

void	ft_print_str(t_printf *tab, const char *str)
{
	int	len;

	if (!str)
		str = ft_set_null(tab);
	len = ft_strlen(str);
	if (tab->pnt)
	{
		len = ft_min(len, tab->prc);
		tab->prc = 0;
	}
	tab->hash = 0;
	ft_update_tab(tab, len);
	if (!tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
	tab->tl += write(1, str, len);
	if (tab->dash)
		while (tab->wdt-- > 0)
			tab->tl += write(1, " ", 1);
}
