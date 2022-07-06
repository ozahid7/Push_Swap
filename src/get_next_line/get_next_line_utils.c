/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:06:55 by ozahid-           #+#    #+#             */
/*   Updated: 2022/07/06 16:15:44 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/get_next_line.h"

int	ft_strlen_g(char *str)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat_g(char *dst, char *src)
{
	size_t	i;
	size_t	dlen;

	if (src == 0)
		return (0);
	dlen = ft_strlen_g(dst);
	i = 0;
	while (src[i])
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[i + dlen] = '\0';
	return (0);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*str;
	int		len;

	len = 0;
	if (s1)
		len = ft_strlen_g(s1);
	len += ft_strlen_g(s2);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = 0;
	ft_strlcat_g(str, s1);
	ft_strlcat_g(str, s2);
	free(s1);
	return (str);
}
