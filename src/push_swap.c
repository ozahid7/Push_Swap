/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/26 23:29:32 by ozahid-          ###   ########.fr       */
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
		ptr->sa.item[j].pos = -1;
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

void	ready_pushto_b(t_main *ptr, int j)
{
	int	i;

	i = ptr->sa.len - 1;
	while (check_pos(*ptr, j))
	{
		if (ptr->sa.item[i].pos <= j)
		{
			ft_push_to(ptr, 'b');
			i = ptr->sa.len - 1;
		}
		else
			ft_rab(ptr, 'a');
	}
}

void	push_b(t_main *ptr)
{
	int	j;

	j = 20;
	while (j <= 100)
	{
		ready_pushto_b(ptr, j);
		j += 20;
	}
}


int	main(int ac, char **av)
{
	t_main	ptr;
	int		i;
	int		j;
	int		a;

	if (parser(&ptr, ac, av))
		return (ft_printf("Error\n"), 1);
	if (check_empty(ptr))
		return (ft_printf("Error\n"), 1);
	if (clone_data(&ptr))
		return (ft_printf("Error\n"), 1);
	if (!ft_sorted(ptr))
		return (ft_printf("numbers are sorted"), 1);
	set_pos(&ptr);
	push_b(&ptr);
	a = ptr.sb.len;
	i = ptr.sb.len - 1;
	printf("\nsa.value |  sa.pos  \n");
	printf("--------------------\n");
	j = ptr.sa.len;
	while (j-- > 0)
		printf("    %d    |    %d   \n", ptr.sa.item[j].value, ptr.sa.item[j].pos);
	i = ptr.sb.len;
	printf("\nsb.value |  sb.pos  \n");
	printf("--------------------\n");
	while (i-- > 0)
		printf("    %d    |    %d  \n", ptr.sb.item[i].value, ptr.sb.item[i].pos);
	printf("sb.len = %d\n", ptr.sb.len);
	printf("sa.len = %d\n", ptr.sa.len);
	return (0);
}
