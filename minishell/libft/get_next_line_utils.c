/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:11:12 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 17:27:38 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_buflen(const char *str)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (!(str[i]))
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strbufjoin(char **line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(*line) + ft_buflen(buf) + 1));
	if (!str)
		return (0);
	while ((*line)[i])
	{
		str[j] = (*line)[i];
		i++;
		j++;
	}
	i = 0;
	while (i < ft_buflen(buf))
	{
		str[j] = buf[i];
		i++;
		j++;
	}
	str[j] = 0;
	free(*line);
	return (str);
}

char	*ft_strdupgnl(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
