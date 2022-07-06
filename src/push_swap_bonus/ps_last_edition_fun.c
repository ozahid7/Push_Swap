/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_last_edition_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:40:03 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/06 23:42:36 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rrr(t_main *ptr)
{
	ft_rrab(ptr, 'a');
	ft_rrab(ptr, 'b');
}

void	ft_ss(t_main *ptr)
{
	ft_sab(ptr, 'a');
	ft_sab(ptr, 'b');
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}
