/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilis_fun_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:22:49 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/04 23:04:52 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(char *str, int *e)
{
	long long int	i;
	int				s;
	long long int	r;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] && str[i] < 32)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		if ((r > 2147483647 && s == 1) || (r * s < -2147483648))
			*e = 1;
		i++;
	}
	return (r * s);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src)
{
	size_t	i;
	size_t	dlen;

	if (src == 0)
		return (0);
	dlen = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[i + dlen] = '\0';
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = 0;
	if (s1)
		len = ft_strlen(s1);
	len += ft_strlen(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = 0;
	ft_strlcat(str, s1);
	ft_strlcat(str, s2);
	free (s1);
	return (str);
}

void	ft_freeit(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
