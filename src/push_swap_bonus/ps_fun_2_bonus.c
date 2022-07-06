/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_fun_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:06:00 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/06 22:57:41 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_all(t_main *ptr)
{
	free(ptr->sa.item);
	free(ptr->sb.item);
}

char	**freeit(char **str, int k)
{
	while (str[k])
	{
		free(str[k]);
		k--;
	}
	free(str);
	return (0);
}

char	**ft_alloc(char **str, char c, char *s, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (s[i] && countword(s, c) != (size_t)k)
	{
		while (s[i] && s[i] == c)
			i++;
		str[k] = (char *) ft_calloc(wordlen(s, c, i) + 1, sizeof(char));
		if (!str[k])
			return (freeit(str, k));
		while (s[i] && s[i] != c)
			str[k][j++] = s[i++];
		str[k++][j] = '\0';
		j = 0;
	}
	str[k] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;
	int		k;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	k = 0;
	j = 0;
	str = (char **) ft_calloc((countword(s, c)) + 1, sizeof(char *));
	if (!str)
		return (0);
	ft_alloc(str, c, s, i);
	return (str);
}

int	ft_sorted(t_main ptr)
{
	int	i;

	i = ptr.sa.len - 1;
	while (i > 0)
	{
		if (ptr.sa.item[i].value > ptr.sa.item[i - 1].value)
			return (1);
		i--;
	}
	return (0);
}
