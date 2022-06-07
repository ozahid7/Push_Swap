/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/07 02:40:36 by ozahid-          ###   ########.fr       */
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
			if (ptr.args[i][j] < 47 || ptr.args[i][j] > 57)
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
	
	str = NULL;
	if (ac == 1)
        return (ft_printf("Error\n"), 1);
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

int	clone_data(t_main *ptr)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	ptr->len = argslen(*ptr);
	ptr->values = (int *)malloc(sizeof(int) * ptr->len);
	if (!ptr->values)
		return (0);
	while(ptr->args[i])
	{
		ptr->values[j] = ft_atoi(ptr->args[i]);
		i++;
		j++;
	}
	return (0);
}

int main(int ac, char **av)
{
    int     i;
    t_main	ptr;
    i = 0;
	if (parser(&ptr, ac, av))
		return (ft_printf("Error\n"), 1);
	if (check_empty(ptr))
		return (ft_printf("Error\n"), 1);
	if (clone_data(&ptr))
		return (ft_printf("Error\n"), 1);
	while (i < ptr.len)
	{
		printf("%d\n", ptr.values[i]);
		i++;
	}
	ft_free(ptr.args);	
	return (0);
}
