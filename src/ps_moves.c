/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:00:59 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/22 01:02:00 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sab(t_main *ptr, char c)
{
	int	tmp;
	int	len;

	if (ptr->sa.len > 1 && c == 'a')
	{
		len = ptr->sa.len - 1;
		tmp = ptr->sa.item[len].value;
		ptr->sa.item[len].value = ptr->sa.item[len - 1].value;
		ptr->sa.item[len - 1].value = tmp;
	}
	if (ptr->sb.len > 1 && c == 'b')
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
	
	if (c == 'a'  && ptr->sa.len > 1)
	{
		len = ptr->sa.len - 1;
		tmp = ptr->sa.item[len].value;
		while (len > 1)
		{
			ptr->sa.item[len].value  = ptr->sa.item[len - 1].value;
			len--;
		}
		ptr->sa.item[len].value = tmp;
	}
	if (c == 'b'  && ptr->sa.len > 1)
	{
		tmp = ptr->sb.item[len].value;
		len = ptr->sa.len - 1;
		while (len > 1)
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
	int	i;
	
	i = 0;
	if (c == 'a' && ptr->sa.len > 1)
	{
		tmp = ptr->sa.item[i].value;
		while (i < ptr->sa.len - 1)
		{
			ptr->sa.item[i].value = ptr->sa.item[i + 1].value;
			i++;
		}
		ptr->sa.item[i].value = tmp;
	}
	if (c == 'b'  && ptr->sa.len > 1)
	{
		tmp = ptr->sb.item[i].value;
		while (i < ptr->sb.len - 1)
		{
			ptr->sb.item[i].value = ptr->sb.item[i + 1].value;
			i++;
		}
		ptr->sb.item[i].value = tmp;
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