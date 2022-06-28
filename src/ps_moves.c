/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:00:59 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/28 01:13:55 by ozahid-          ###   ########.fr       */
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

void ft_rotate(t_stacks *stack)
{
	int	len;
	t_item	tmp;

	if (stack->len > 1)
	{
		len = stack->len - 1;
		tmp = stack->item[len];
		while (len > 0)
		{
			stack->item[len] = stack->item[len - 1];
			len--;
		}
		stack->item[len] = tmp;
	}
}

void	ft_rab(t_main *ptr, char c)
{
	if (c == 'a' && ptr->sa.len > 1)
	{
		ft_rotate(&ptr->sa);
	}
	if (c == 'b' && ptr->sb.len > 1)
	{
		ft_rotate(&ptr->sb);
	}	
	printf("r%c\n", c);
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
	if (c == 'b' && ptr->sb.len > 1)
	{
		tmp = ptr->sb.item[i];
		while (i < ptr->sb.len - 1)
		{
			ptr->sb.item[i] = ptr->sb.item[i + 1];
			i++;
		}
		ptr->sb.item[i] = tmp;
	}
	printf("rr%c\n", c);
}

void	ft_rrr(t_main ptr)
{
	ft_rrab(&ptr, 'a');
	ft_rrab(&ptr, 'b');
}

void	ft_rr(t_main *ptr)
{
	ft_rotate(&ptr->sa);
	ft_rotate(&ptr->sb);
	printf("rr\n");
}

void	ft_ss(t_main ptr)
{
	ft_sab(&ptr, 'a');
	ft_sab(&ptr, 'b');
}
