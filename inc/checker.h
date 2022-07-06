/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:27:46 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/06 23:44:06 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "ft_printf.h"
# include "get_next_line.h"

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
	char		*ins;
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
void	ft_error(void);

//instructions
void	ft_rab(t_main *ptr, char c);
void	ft_sab(t_main *ptr, char c);
void	ft_rrab(t_main *ptr, char c);
void	ft_rr(t_main *ptr);
void	ft_ss(t_main *ptr);
void	ft_rrr(t_main *ptr);

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

#endif