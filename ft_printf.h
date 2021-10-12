/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 22:46:43 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/12 22:47:25 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_printf
{
	va_list		args;

	int			wdt;
	int			prc;
	int			zero;
	int			pnt;
	int			dash;
	int			tl;
	int			sign;
	int			sp;
	int			hash;
	int			plus;

	char		base[17];
	char		prefix[3];
	char		null[7];
	char		cnv_list[10];
	char		flg_list[8];

	int			cnv_hash[256];
	int			flg_hash[256];
	void		(*cnv_eval[9])(struct s_printf *);
	int			(*flg_eval[7])(struct s_printf *, const char *, int);
}		t_printf;

#endif
