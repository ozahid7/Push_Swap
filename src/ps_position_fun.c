/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_position_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:09:14 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/26 20:54:24 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_start(t_main *ptr)
{
	int	i;

	i = ptr->sa.len - 1;
	while (i >= 0)
	{
		if (ptr->sa.item[i].pos == -1)
			return (ptr->sa.item[i].value);
		i--;
	}
	return (0);
}

int	get_pos(t_main *ptr)
{
	int	i;
	int	small;
	int	pos;

	i = ptr->sa.len - 1;
	pos = ptr->sa.len - 1;
	small = get_start(ptr);
	i = ptr->sa.len - 1;
	while (i >= 0)
	{
		if (small >= ptr->sa.item[i].value && ptr->sa.item[i].pos == -1)
		{
			small = ptr->sa.item[i].value;
			pos = i;
		}
		i--;
	}
	return (pos);
}

void	set_pos(t_main *ptr)
{
	int	i;
	int	pos;

	i = 0;
	while (i++ < ptr->sa.len)
	{
		pos = get_pos(ptr);
		ptr->sa.item[pos].pos = i;
	}
}
