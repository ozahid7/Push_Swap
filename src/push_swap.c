/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/23 02:51:36 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (i >= 0)
	{
		ptr->sa.item[j].value = ft_atoi(ptr->args[i]);
		i--;
		j++;
	}
	ft_freeit(ptr->args);
	return (0);
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

void	t_sort(t_main *ptr)
{
	if ((ptr->sa.item[0].value > ptr->sa.item[2].value
			&& ptr->sa.item[1].value < ptr->sa.item[2].value)
		|| (ptr->sa.item[1].value < ptr->sa.item[2].value
			&& ptr->sa.item[1].value > ptr->sa.item[0].value)
		|| (ptr->sa.item[0].value > ptr->sa.item[2].value
			&& ptr->sa.item[2].value < ptr->sa.item[1].value))
		ft_sab(ptr, 'a');
	if ((ptr->sa.item[1].value > ptr->sa.item[2].value
			&& ptr->sa.item[1].value > ptr->sa.item[0].value))
		ft_rrab(ptr, 'a');
	if (ptr->sa.item[2].value > ptr->sa.item[0].value
		&& ptr->sa.item[1].value < ptr->sa.item[2].value)
		ft_rab(ptr, 'a');
}

void	push_small(t_main *ptr)
{
	int	i;

	i = ptr->sa.len - 1;
	ptr->small = ptr->sa.item[i].value;
	ptr->pos = ptr->sa.len - 1;
	while (i >= 0)
	{
		if (ptr->sa.item[i].value < ptr->small)
		{
			ptr->small = ptr->sa.item[i].value;
			ptr->pos--;
		}
		i--;
	}
	printf("pos = %d\n", ptr->pos);
	printf("small = %d\n", ptr->small);
}

// void	f_sort(t_main *ptr)
// {
	
// }

int	main(int ac, char **av)
{
	t_main	ptr;
	int		i;

	i = 0;
	if (parser(&ptr, ac, av))
		return (ft_printf("Error\n"), 1);
	if (check_empty(ptr))
		return (ft_printf("Error\n"), 1);
	if (clone_data(&ptr))
		return (ft_printf("Error\n"), 1);
	if (!ft_sorted(ptr))
		return (ft_printf("numbers are sorted"), 1);
	// t_sort(&ptr);
	push_small(&ptr);
	// i = ptr.sb.len;
	// while (i-- > 0)
	// 	printf("%d\n", ptr.sb.item[i].value);
	int j = ptr.sa.len;
	while (j-- > 0)
		printf("%d\n", ptr.sa.item[j].value);
	return (0);
}
