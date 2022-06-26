/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tree_five_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:11:26 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/26 23:28:53 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_small(t_main *ptr)
{
	int	i;

	i = ptr->sa.len - 1;
	ptr->pos = ptr->sa.len - 1;
	ptr->small = ptr->sa.item[i].value;
	while (i >= 0)
	{
		if (ptr->sa.item[i].value < ptr->small)
		{
			ptr->small = ptr->sa.item[i].value;
			ptr->pos = i;
		}
		i--;
	}
	return (ptr->small);
}

void	push_small(t_main *ptr)
{
	int	i;

	i = ptr->sa.len - 1;
	find_small(ptr);
	while (1)
	{
		if (ptr->sa.item[i].value != ptr->small && ptr->pos > i / 2)
			ft_rrab(ptr, 'a');
		else if (ptr->sa.item[i].value != ptr->small && ptr->pos <= i / 2)
			ft_rab(ptr, 'a');
		else
			break ;
	}
	ft_push_to(ptr, 'b');
}

void	f_sort(t_main *ptr)
{
	while (ptr->sa.len > 3)
	{
		push_small(ptr);
	}
	if (ft_sorted(*ptr))
		t_sort(ptr);
	while (ptr->sb.len > 0)
	{
		ft_push_to(ptr, 'a');
	}
}
