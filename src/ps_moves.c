/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:00:59 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/26 21:30:36 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab(t_main *ptr, char c)
{
	t_item	tmp;
	int	len;

	if (ptr->sa.len > 1 && c == 'a')
	{
		len = ptr->sa.len - 1;
		tmp = ptr->sa.item[len];
		ptr->sa.item[len] = ptr->sa.item[len - 1];
		ptr->sa.item[len - 1] = tmp;
	}
	if (ptr->sb.len > 1 && c == 'b')
	{
		len = ptr->sb.len - 1;
		tmp = ptr->sb.item[len];
		ptr->sb.item[len] = ptr->sb.item[len - 1];
		ptr->sb.item[len - 1] = tmp;
	}
}

void	ft_rab(t_main *ptr, char c)
{
	int	len;
	t_item	tmp;

	if (c == 'a' && ptr->sa.len > 1)
	{
		len = ptr->sa.len - 1;
		tmp = ptr->sa.item[len];
		while (len > 0)
		{
			ptr->sa.item[len] = ptr->sa.item[len - 1];
			len--;
		}
		ptr->sa.item[len] = tmp;
	}
	if (c == 'b' && ptr->sa.len > 1)
	{
		tmp = ptr->sb.item[len];
		len = ptr->sa.len - 1;
		while (len > 0)
		{
			ptr->sb.item[len] = ptr->sb.item[len - 1];
			len--;
		}
		ptr->sb.item[len] = tmp;
	}	
}

void	ft_rrab(t_main *ptr, char c)
{
	t_item	tmp;
	int	i;

	i = 0;
	if (c == 'a' && ptr->sa.len > 1)
	{
		tmp = ptr->sa.item[i];
		while (i < ptr->sa.len - 1)
		{
			ptr->sa.item[i] = ptr->sa.item[i + 1];
			i++;
		}
		ptr->sa.item[i] = tmp;
	}
	if (c == 'b' && ptr->sa.len > 1)
	{
		tmp = ptr->sb.item[i];
		while (i < ptr->sb.len - 1)
		{
			ptr->sb.item[i] = ptr->sb.item[i + 1];
			i++;
		}
		ptr->sb.item[i] = tmp;
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
