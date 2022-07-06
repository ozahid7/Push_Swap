/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 23:57:38 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/06 16:12:08 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strjoin_g(char *s1, char *s2);
size_t	ft_strlcat_g(char *dst, char *src);
int		ft_strlen_g(char *str);
char	*get_next_line(int fd);

#endif
