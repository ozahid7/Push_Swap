/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 17:40:27 by ozahid-           #+#    #+#             */
/*   Updated: 2022/05/13 22:23:41 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	ft_print(char c, va_list ptr)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(ptr, int));
	else if (c == 'd')
		counter += ft_putnbr(va_arg(ptr, int));
	else if (c == 'i')
		counter += ft_putnbr(va_arg(ptr, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(ptr, char *));
	else if (c == 'u')
		counter += ft_unsignednumber(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_hexa(va_arg(ptr, unsigned int), c);
	else if (c == 'p')
		counter += ft_argp(va_arg(ptr, unsigned long));
	else
		counter += ft_putchar(c);
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		counter;
	va_list	ptr;

	i = 0;
	counter = 0;
	va_start(ptr, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter += ft_print(str[i], ptr);
		}
		else
			counter += ft_putchar(str[i]);
		i++;
	}
	va_end(ptr);
	return (counter);
}
