/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/21 00:40:26 by ozahid-          ###   ########.fr       */
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
	
	i = argslen(*ptr) - 1;
	j = 0;
	ptr->sa.len = argslen(*ptr);
	ptr->sb.len = 0;
	ptr->len = argslen(*ptr);
	ptr->sa.item = (t_item *)malloc(sizeof(t_item *) * ptr->len);
	if (!ptr->sa.item)
		return (0);
	ptr->sb.item = (t_item *)malloc(sizeof(t_item *) * ptr->len);
	if (!ptr->sb.item)
		return (0);
	while(ptr->args[i])
	{
		ptr->sa.item[j].value = ft_atoi(ptr->args[i]);
		i--;
		j++;
	}
	ft_free(ptr->args);	
	return (0);
}
void	ft_sab(t_main *ptr, char c)
{
	int	tmp;
	int	len;

	if (ptr->len > 1 && c == 'a')
	{
		len = ptr->sa.len - 1;
		tmp = ptr->sa.item[len].value;
		ptr->sa.item[len].value = ptr->sa.item[len - 1].value;
		ptr->sa.item[len - 1].value = tmp;
	}
	if (ptr->len > 1 && c == 'b')
	{
		len = ptr->sb.len - 1;
		tmp = ptr->sb.item[len].value;
		ptr->sb.item[len].value = ptr->sb.item[len - 1].value;
		ptr->sb.item[len - 1].value = tmp;
	}
}

void	ft_rab(t_main *ptr, char c)
{
	int len;
	int	tmp;
	
	if (c == 'a')
	{
		len = ptr->sa.len - 1;
		tmp = ptr->sa.item[len].value;
		while (len > 0 && ptr->len > 1)
		{
			ptr->sa.item[len].value  = ptr->sa.item[len - 1].value;
			len--;
		}
		ptr->sa.item[len].value = tmp;
	}
	if (c == 'b')
	{
		tmp = ptr->sb.item[len].value;
		len = ptr->sa.len - 1;
		while (len > 0 && ptr->len > 1)
		{
			ptr->sb.item[len].value  = ptr->sb.item[len - 1].value;
			len--;
		}
		ptr->sb.item[len].value = tmp;
	}
		
}

void	ft_rrab(t_main *ptr, char c)
{
	int	tmp;
	int	len;
	
	if (c == 'a')
	{
		tmp = ptr->sa.item[ptr->len - 1].value;
		len = ptr->sa.len - 1;
		while (len-- > 0 && ptr->len > 1)
			ptr->sa.item[len].value = ptr->sa.item[len - 1].value;
		ptr->sa.item[len].value = tmp;
	}
	if (c == 'b')
	{
		tmp = ptr->sb.item[ptr->len - 1].value;
		len = ptr->sb.len - 1;
		while (len-- > 0 && ptr->len > 1)
			ptr->sb.item[len].value = ptr->sb.item[len - 1].value;
		ptr->sb.item[len].value = tmp;
	}
}

void	ft_rrr(t_main ptr)
{
	ft_rrab(&ptr, 'a');
	ft_rrab(&ptr, 'b');
}

void	ft_ss(t_main ptr)
{
	ft_sab(&ptr, 'a');
	ft_sab(&ptr, 'b');
}

void	ft_push_to(t_main *ptr, char c)
{
	int	i;
	int	lena;
	int	lenb;

	i = 0;
	lena = ptr->sa.len - 1;
	lenb = ptr->sb.len;
	if (c == 'b' && ptr->sa.len != 0)
	{
		ptr->sb.item[lenb].value = ptr->sa.item[lena].value;
		ptr->sb.len++;
		ptr->sa.len--;
	}
	if (c == 'a' && ptr->sb.len != 0)
	{
		ptr->sa.item[lena].value = ptr->sb.item[lenb].value;
		ptr->sa.len++;
		ptr->sb.len--;
	}
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
	ft_rab(&ptr, 'a');
		i = ptr.sa.len;
	while (i-- > 0)
		printf("%d\n", ptr.sa.item[i].value);
	return (0);
}
