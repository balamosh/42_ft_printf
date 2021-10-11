#include "ft_printf.h"

void	ft_eval_unsigned_int(t_print *tab)
{
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0 && tab->prc == 0 && tab->pnt == 1)
		ft_print_empty(tab);
	else
		ft_print_unsigned_int(tab, nb);
}

void	ft_putnbr_un(unsigned int nb)
{
	if (nb >= 10)
		ft_putnbr_un(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
}

void	ft_print_unsigned_int(t_printf *tab, unsigned int nb)
{
	int	len;

	len = ft_numlen(nb, 10);
	tab->hash = 0;
	ft_update_tab(tab, len);
	ft_print_nbr_left(tab);
	ft_putnbr_un(nb);
	tab->tl += len;
	ft_print_nbr_right(tab);
}
