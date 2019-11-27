/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/06 16:11:12 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 18:53:06 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buf) + 1))))
		return (0);
	while (line[i])
	{
		str[j] = line[i];
		i++;
		j++;
	}
	i = 0;
	while (buf[i])
	{
		str[j] = buf[i];
		i++;
		j++;
	}
	str[j] = 0;
	free((void *)line);
	buf[0] = 0;
	return (str);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = malloc((i + 1) * sizeof(char))))
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

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str2;

	str2 = (char *)str;
	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == 0)
	{
		if (c == 0)
			return (str2 + i);
		else
			return (0);
	}
	else
		return (str2 + i);
}
