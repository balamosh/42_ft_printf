/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sotherys <sotherys@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 22:12:11 by sotherys          #+#    #+#             */
/*   Updated: 2021/10/14 22:48:24 by sotherys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen(unsigned long int nb, int base_len)
{
	int	i;

	if (nb == 0)
		return (1);
	i = 0;
	while (nb > 0)
	{
		nb = nb / base_len;
		i++;
	}
	return (i);
}
