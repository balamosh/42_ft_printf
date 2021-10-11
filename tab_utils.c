#include "ft_printf.h"

void	ft_reset_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->sign = 0;
	tab->sp = 0;
	tab->hash = 0;
	tab->plus = 0;
	tab->prefix[0] = '\0';
}

void	ft_init_tab(t_print *tab)
{
	ft_reset_tab(tab);
	tab->tl = 0;
}

static void	fill_functions_hash(int *hash, const char *str)
{
	int	i;

	i = 0;
	while (i < 256)
		hash[i++] = -1;
	i = 0;
	while (str[i])
	{
		hash[(int) str[i]] = i;
		++i;
	}
}

void	t_printf_constructor(t_printf *tab)
{
	fill_functions_hash(cnv_hash, "cspdiuxX%");
	fill_functions_hash(flg_hash, "-0.*# +");
	tab->cnv_eval[0] = &ft_eval_char;
	tab->cnv_eval[1] = &ft_eval_str;
	tab->cnv_eval[2] = &ft_eval_pointer;
	tab->cnv_eval[3] = &ft_eval_int;
	tab->cnv_eval[4] = &ft_eval_int;
	tab->cnv_eval[5] = &ft_eval_unsigned_int;
	tab->cnv_eval[6] = &ft_eval_hex_low;
	tab->cnv_eval[7] = &ft_eval_hex_cap;
	tab->cnv_eval[8] = &ft_eval_percent;
	tab->flg_eval[0] = &ft_flag_dash;
	tab->flg_eval[1] = &ft_flag_zero;
	tab->flg_eval[2] = &ft_flag_point;
	tab->flg_eval[3] = &ft_flag_star;
	tab->flg_eval[4] = &ft_flag_hash;
	tab->flg_eval[5] = &ft_flag_space;
	tab->flg_eval[6] = &ft_flag_plus;
}