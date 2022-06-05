/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:27:46 by ozahid-           #+#    #+#             */
/*   Updated: 2022/06/05 20:48:44 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

typedef struct s_main
{
    char **args;
} t_main;


size_t  ft_strlcat(char *dst, char *src);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
int     ft_atoi(char *str);
void	ft_free(char **args);




size_t	countword(char *str, char c);
size_t	wordlen(char *str, char c, int i);
char	**freeit(char **str, int k);
char	**ft_alloc(char **str, char c, char *s, int i);
char	**ft_split(char *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);

#endif