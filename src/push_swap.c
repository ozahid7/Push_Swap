/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/05 20:50:59 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int    check_args_int(t_main ptr)
{
	int i;
	int j;
	
	i = 0;
	while (ptr.args[i])
	{
		j = 0;
		while (ptr.args[i][j])
		{
			if (ptr.args[i][j] < 48 || ptr.args[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_empty(t_main ptr)
{
	int i;
	int j;
	
	i = 0;
	if (ptr.args[i] == 0)
		return (1);
	while (ptr.args[i])
	{
		j = 0;
		while (ptr.args[i][j])
		{
			if (ptr.args[i][j] == ' ')
				j++;
			else if (ptr.args[i][j] != ' ' && check_args_int(ptr))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	parser(t_main *ptr, int ac, char **av)
{
	int		i;
	char	*str;
	i = 1;
	
	if (ac == 1)
        return (1);
    while (ac > 1 && av[i])
    {
        str = ft_strjoin(str, av[i]);
        str = ft_strjoin(str, " ");
        i++;
    }
	ptr->args = ft_split(str, ' ');
	free(str);
	return 0;
}
void	ft_free(char **args)
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

int main(int ac, char **av)
{
    int     args;
    t_main	ptr;    
    args = 1;
	if (parser(&ptr, ac, av))
		return (ft_printf("Error"), 1);
	return (0);
}
