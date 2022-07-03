/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/03 23:19:10 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	clone_data(t_main *ptr)
{
	int	i;
	int	j;
	int	e;

	i = argslen(*ptr);
	j = 0;
	ptr->sa.len = argslen(*ptr);
	ptr->sb.len = 0;
	ptr->len = argslen(*ptr);
	ptr->sa.item = (t_item *)malloc(sizeof(t_item *) * ptr->len);
	if (!ptr->sa.item)
		return (1);
	ptr->sb.item = (t_item *)malloc(sizeof(t_item *) * ptr->len);
	if (!ptr->sb.item)
		return (free(ptr->sa.item), 1);
	while (--i >= 0)
	{
		ptr->sa.item[j].value = ft_atoi(ptr->args[i], &e);
		if (e == 1)
			return (1);
		ptr->sa.item[j].pos = -1;
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
	if (c == 'b' && ptr->sa.len != 0)
	{
		lena = ptr->sa.len - 1;
		lenb = ptr->sb.len;
		ptr->sb.item[lenb] = ptr->sa.item[lena];
		ptr->sb.len++;
		ptr->sa.len--;
	}
	if (c == 'a' && ptr->sb.len != 0)
	{
		lena = ptr->sa.len;
		lenb = ptr->sb.len - 1;
		ptr->sa.item[lena] = ptr->sb.item[lenb];
		ptr->sa.len++;
		ptr->sb.len--;
	}
	ft_printf("p%c\n", c);
}

void	push_back(t_main *ptr)
{
	while (ptr->sb.len > 0)
	{
		push_to_a(ptr);
	}
}

void	final_sort(t_main *ptr)
{
	if (ptr->sa.len < 4)
		t_sort(ptr);
	else if (ptr->sa.len < 6)
		f_sort(ptr);
	else if (ptr->sa.len < 101)
		oh_fh_sort(ptr, 5);
	else if (ptr->sa.len > 100)
		oh_fh_sort(ptr, 10);
}

int	main(int ac, char **av)
{
	t_main	ptr;

	if (parser(&ptr, ac, av))
		return (ft_freeit(ptr.args), ft_printf("Error\n"), 1);
	if (clone_data(&ptr))
	{
		free_all(&ptr);
		return (ft_printf("Error\n"), 1);
	}
	if (check_multi(&ptr))
	{
		free_all(&ptr);
		return (ft_printf("Error\n", 1));
	}
	if (!ft_sorted(ptr))
	{
		free_all(&ptr);
		return (0);
	}
	set_pos(&ptr);
	final_sort(&ptr);
	free_all(&ptr);
}
