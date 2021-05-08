/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tprat <tprat@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:16:32 by tprat             #+#    #+#             */
/*   Updated: 2021/05/07 17:34:33 by tprat            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	take_rest(char **line, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if (!((*line)[i]))
		return (1);
	(*line)[i] = 0;
	i++;
	while ((*line)[i])
		buf[j++] = (*line)[i++];
	buf[j] = 0;
	tmp = *line;
	*line = ft_strdupgnl(*line);
	if (!(*line))
		return (0);
	free(tmp);
	return (1);
}

int	choose_return(char *buf, int rsize)
{
	if (rsize == -1)
		return (-1);
	if (buf[0] || rsize != 0)
		return (1);
	return (0);
}

void	clear_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
}

int	get_next_line(int fd, char **line)
{
	static int	rsize;
	static char	buf[BUFFER_SIZE];

	if (!(rsize))
		rsize = read(fd, buf, BUFFER_SIZE);
	*line = ft_strdupgnl("");
	if (!(*line))
		return (-1);
	while (rsize > 0)
	{
		if (buf[0])
		{
			*line = ft_strbufjoin(line, buf);
			if (!(*line))
				return (-1);
			clear_buf(buf);
		}
		else
			rsize = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	if (!(take_rest(line, buf)))
		return (-1);
	return (choose_return(buf, rsize));
}
