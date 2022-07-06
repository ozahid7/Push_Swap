/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/06 23:54:29 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}


int	do_ins(t_main *ptr)
{
	if (!strcmp("ra\n", ptr->ins))
		ft_rab(ptr, 'a');
	else if (!strcmp(ptr->ins, "rb\n"))
		ft_rab(ptr, 'b');
	else if (!strcmp(ptr->ins, "sa\n"))
		ft_sab(ptr, 'a');
	else if (!strcmp(ptr->ins, "sb\n"))
		ft_sab(ptr, 'b');
	else if (!strcmp(ptr->ins, "rra\n"))
		ft_rrab(ptr, 'a');
	else if (!strcmp(ptr->ins, "rrb\n"))
		ft_rrab(ptr, 'b');
	else if (!strcmp(ptr->ins, "rrr\n"))
		ft_rrr(ptr);
	else if (!strcmp(ptr->ins, "rr\n"))
		ft_rr(ptr);
	else if (!strcmp(ptr->ins, "ss\n"))
		ft_ss(ptr);
	else if (!strcmp(ptr->ins, "pa\n"))
		ft_push_to(ptr, 'a');
	else if (!strcmp(ptr->ins, "pb\n"))
		ft_push_to(ptr, 'b');
	else
		return (1);
	return (0);
}

int	read_ins(t_main *ptr)
{
	int	i;

	i = 0;
	ptr->ins = get_next_line(0);
	while (ptr->ins)
	{
		if (do_ins(ptr))
			return (1);
		ptr->ins = get_next_line(0);
	}
	if (ptr->ins == 0)
	{
		if (!ft_sorted(*ptr) && ptr->sb.len == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_main	ptr;

	if (parser(&ptr, ac, av))
		return (ft_error(), 1);
	if (clone_data(&ptr))
	{
		free_all(&ptr);
		return (ft_error(), 1);
	}
	if (check_multi(&ptr))
	{
		free_all(&ptr);
		return (ft_error(), 1);
	}
	if (read_ins(&ptr))
		return (ft_error(), 1);
}
