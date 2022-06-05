/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 03:44:48 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/13 22:23:29 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_counter(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

void	ft_rcrsv(unsigned int nb, char *base)
{
	if (nb >= 16)
	{
		ft_rcrsv(nb / 16, base);
		ft_rcrsv(nb % 16, base);
	}
	else
		ft_putchar(base[nb]);
}

int	ft_hexa(unsigned int nb, char arg)
{
	int		i;
	char	*base;

	i = ft_counter(nb);
	if (arg == 'x')
		base = "0123456789abcdef";
	if (arg == 'X')
		base = "0123456789ABCDEF";
	ft_rcrsv(nb, base);
	return (i);
}
