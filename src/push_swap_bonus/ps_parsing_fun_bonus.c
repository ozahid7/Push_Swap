/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing_fun_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:06:08 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/04 23:06:01 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_args_int(char ch, int *sig)
{
	if ((ch > 47 && ch < 58))
		return (0);
	else if ((ch == '-' || ch == '+') && *sig == 0)
	{
		*sig = 1;
		return (0);
	}
	return (1);
}

int	check_multi(t_main *ptr)
{
	int	i;
	int	j;
	int	tmp;

	i = ptr->sa.len - 1;
	while (i >= 0)
	{
		tmp = ptr->sa.item[i].value;
		j = i - 1;
		while (j >= 0)
		{
			if (tmp == ptr->sa.item[j].value)
				return (1);
			j--;
		}
		i--;
	}
	return (0);
}

int	check_empty(char **av)
{
	int		i;
	int		j;
	int		s;
	int		sig;

	i = 0;
	while (av[++i])
	{
		s = 0;
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				sig = 0;
				s++;
			}
			else if (check_args_int(av[i][j], &sig))
				return (1);
			j++;
		}
		if (s == ft_strlen(av[i]))
			return (1);
	}
	return (0);
}

int	parser(t_main *ptr, int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	str = NULL;
	if (ac == 1)
		return (1);
	if (check_empty(av))
		return (1);
	while (ac > 1 && av[i])
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	ptr->args = ft_split(str, ' ');
	free(str);
	return (0);
}

int	argslen(t_main ptr)
{
	int	i;

	i = 0;
	if (ptr.args == 0)
		return (0);
	while (ptr.args[i])
	{
		i++;
	}
	return (i);
}
