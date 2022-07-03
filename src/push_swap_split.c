/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:07:53 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/03 23:07:53 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char *)b;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}

size_t	countword(char *str, char c)
{
	size_t	i;
	size_t	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			k++;
			while (str[i] != c && str[i])
				i++;
		}
		else
			i++;
	}
	return (k);
}

size_t	wordlen(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}
