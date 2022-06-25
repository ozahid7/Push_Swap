/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:06:01 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/25 23:53:45 by ozahid-          ###   ########.fr       */
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
	lena = ptr->sa.len;
	lenb = ptr->sb.len;
	if (c == 'b' && ptr->sa.len != 0)
	{
		lena--;
		ptr->sb.item[lenb].value = ptr->sa.item[lena].value;
		ptr->sb.len++;
		ptr->sa.len--;
	}
	if (c == 'a' && ptr->sb.len != 0)
	{
		lenb--;
		ptr->sa.item[lena].value = ptr->sb.item[lenb].value;
		ptr->sa.len++;
		ptr->sb.len--;
	}
}

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
	while (i < ptr->sa.len)
	{
		pos = get_pos(ptr);
		ptr->sa.item[pos].pos = i;
		i++;
	}
}

void	oh_sort(t_main *ptr)
{
	int	i;
	//int	pos;
	
	i = ptr->sa.len - 1;
	while (i-- > 0)
	{
		if (ptr->sa.item[i].pos < 20)
			ft_push_to(ptr, 'b');
	}
}

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
	// f_sort(&ptr);
	set_pos(&ptr);
	oh_sort(&ptr);
	// int j = ptr.sa.len;
	// while (j-- > 0)
	// 	printf("%d | %d\n", ptr.sa.item[j].value, ptr.sa.item[j].pos);
	i = ptr.sb.len;
	while (i-- > 0)
		printf("%d\n", ptr.sb.item[i].value);
	return (0);
}
