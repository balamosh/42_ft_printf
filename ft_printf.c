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
			i = ft_eval_format(tab, format, i + 1);
		else
			ret += write(1, &format[i], 1);
		i++;
	}
	ret += tab.tl;
	va_end(tab.args);
	return (ret);
}
