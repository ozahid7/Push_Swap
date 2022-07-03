/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_oneh_fiveh_fun.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:18:27 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/03 00:32:14 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pos(t_main ptr, int pos)
{
	int	i;

	i = ptr.sa.len - 1;
	while (i >= 0)
	{
		if (ptr.sa.item[i].pos <= pos)
			return (1);
		i--;
	}
	return (0);
}

void	ready_pushto_b(t_main *ptr, int j, int r)
{
	int	i;
	int	posb;

	i = ptr->sa.len - 1;
	while (check_pos(*ptr, j))
	{
		if (ptr->sa.item[i].pos <= j)
		{
			ft_push_to(ptr, 'b');
			i = ptr->sa.len - 1;
			posb = ptr->sb.len - 1;
			if (ptr->sb.item[posb].pos < j - r && ptr->sa.item[i].pos > j)
				ft_rr(ptr);
			else if (ptr->sb.item[posb].pos < j - r)
				ft_rab(ptr, 'b');
		}
		else
			ft_rab(ptr, 'a');
	}
}

void	oh_fh_sort(t_main *ptr, int nb)
{
	int	j;
	int	r;

	r = ptr->sa.len / nb;
	j = r;
	while (ptr->sa.len)
	{
		ready_pushto_b(ptr, j, r / 2);
		j += r;
	}
	push_back(ptr);
}

int	get_large(t_main *ptr)
{
	int	i;

	i = ptr->sb.len - 1;
	ptr->posb = ptr->sa.len - 1;
	ptr->large = ptr->sb.item[i].pos;
	while (i >= 0)
	{
		if (ptr->sb.item[i].pos > ptr->large)
		{
			ptr->large = ptr->sb.item[i].pos;
			ptr->posb = i;
		}
		i--;
	}
	return (ptr->large);
}

void	push_to_a(t_main *ptr)
{
	int	i;

	i = ptr->sb.len - 1;
	get_large(ptr);
	while (1)
	{
		if (ptr->sb.item[i].pos != ptr->large && ptr->posb > i / 2)
		{
			ft_rab(ptr, 'b');
		}
		else if (ptr->sb.item[i].pos != ptr->large && ptr->posb <= i / 2)
			ft_rrab(ptr, 'b');
		else
			break ;
	}
	ft_push_to(ptr, 'a');
}
