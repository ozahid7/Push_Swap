/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:27:46 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/03 23:09:10 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"

typedef struct s_item
{
	int	value;
	int	pos;
}	t_item;

typedef struct s_stacks
{
	t_item	*item;
	int		len;
}	t_stacks;

typedef struct s_main
{
	char		**args;
	int			small;
	int			large;
	int			pos;
	int			posb;
	t_stacks	sa;
	t_stacks	sb;
	int			len;
}	t_main;

size_t	ft_strlcat(char *dst, char *src);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_atoi(char *str, int *e);
void	ft_freeit(char **args);
char	**freeit(char **str, int k);
void	free_all(t_main *ptr);

//instructions
void	ft_rab(t_main *ptr, char c);
void	ft_sab(t_main *ptr, char c);
void	ft_rrab(t_main *ptr, char c);
void	ft_rr(t_main *ptr);

//parser
int		argslen(t_main ptr);
void	ft_freeit(char **args);
int		parser(t_main *ptr, int ac, char **av);
int		check_empty(char **av);
int		check_args_int(char ch, int *sig);
int		check_multi(t_main *ptr);

int		clone_data(t_main *ptr);
void	ft_push_to(t_main *ptr, char c);

size_t	countword(char *str, char c);
size_t	wordlen(char *str, char c, int i);
char	**freeit(char **str, int k);
char	**ft_alloc(char **str, char c, char *s, int i);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

//sorting
int		ft_sorted(t_main ptr);
void	t_sort(t_main *ptr);
int		find_small(t_main *ptr);
void	push_small(t_main *ptr);
void	f_sort(t_main *ptr);
void	push_back(t_main *ptr);
void	push_to_a(t_main *ptr);
void	ready_pushto_b(t_main *ptr, int j, int r);

//position
int		get_start(t_main *ptr);
int		get_pos(t_main *ptr);
void	set_pos(t_main *ptr);
int		get_large(t_main *ptr);
void	oh_fh_sort(t_main *ptr, int nb);
int		check_pos(t_main ptr, int pos);

#endif