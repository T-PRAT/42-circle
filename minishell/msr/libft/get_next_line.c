/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:16:02 by rkowalsk          #+#    #+#             */
/*   Updated: 2021/03/17 12:33:02 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFFER_SIZE 100

int	fourtou(char **rest, int fd, char *buffer)
{
	int	ret;

	free(*rest);
	*rest = NULL;
	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret > 0)
		buffer[ret] = '\0';
	return (ret);
}

char	*gnl_store_rest(char *rest, char **line)
{
	int		size_rest;
	char	*tmp;
	char	*chr;

	if (!rest)
		size_rest = 0;
	else
	{
		if (ft_strchr(rest, '\n') != NULL)
			chr = ft_strchr(rest, '\n');
		else
			chr = rest + ft_strlen(rest);
		size_rest = (int)(chr - rest);
	}
	free(*line);
	*line = ft_substr(rest, 0, size_rest);
	if (!*line)
		return (NULL);
	tmp = ft_substr(rest, size_rest + 1, BUFFER_SIZE);
	if (!tmp)
		return (NULL);
	free(rest);
	return (tmp);
}

char	*gnl_new_line(char **line, char *buffer)
{
	int		size_buffer;
	int		size_line;
	char	*tmp;
	char	*chr;

	if (!buffer)
		size_buffer = 0;
	else
	{
		if (ft_strchr(buffer, '\n') != NULL)
			chr = ft_strchr(buffer, '\n');
		else
			chr = buffer + ft_strlen(buffer);
		size_buffer = (int)(chr - buffer);
	}
	size_line = ft_strlen(*line);
	tmp = malloc(sizeof(char) * (size_line + size_buffer + 1));
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	ft_strlcat(tmp, *line, size_line + 1);
	ft_strlcat(tmp, buffer, size_line + size_buffer + 1);
	free(*line);
	*line = tmp;
	return (ft_substr(buffer, size_buffer + 1, BUFFER_SIZE));
}

int	gnl_care_rest(char **rest, char **line)
{
	if (*rest == NULL)
	{
		*rest = ft_strdup("");
		if (!*rest)
			return (-1);
	}
	if (ft_strlen(*rest) > 0)
	{
		if (ft_strchr(*rest, '\n'))
		{
			*rest = gnl_store_rest(*rest, line);
			if (!*rest)
				return (-1);
			return (1);
		}
		else
		{
			*rest = gnl_store_rest(*rest, line);
			if (!*rest)
				return (-1);
		}
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest;
	int			ret;
	char		buffer[BUFFER_SIZE + 1];

	if (!line || (read(fd, buffer, 0) != 0))
		return (-1);
	*line = ft_strdup("");
	buffer[0] = '\0';
	ret = gnl_care_rest(&rest, line);
	if (ret != 0)
		return (ret);
	while (!ft_strchr(buffer, '\n'))
	{
		ret = fourtou(&rest, fd, buffer);
		if (ret == 0)
			return (0);
		if (ret < 0)
			return (-1);
		rest = gnl_new_line(line, buffer);
		if (!rest)
			return (-1);
	}
	buffer[0] = '\0';
	return (1);
}
