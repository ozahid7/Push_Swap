/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:31:20 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/13 22:23:10 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_counterp(unsigned long n)
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

void	ft_rcrsvp(unsigned long nb, char *base)
{
	if (nb >= 16)
	{
		ft_rcrsvp(nb / 16, base);
		ft_rcrsvp(nb % 16, base);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

int	ft_argp(unsigned long nb)
{
	int		i;
	char	*base;

	i = ft_counterp(nb);
	base = "0123456789abcdef";
	i += ft_putstr("0x");
	ft_rcrsvp(nb, base);
	return (i);
}
