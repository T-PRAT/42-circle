/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:16:32 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 18:54:08 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		take_rest(char *line, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!(line[i]))
		return (0);
	line[i] = 0;
	i++;
	while (line[i])
		buf[j++] = line[i++];
	buf[j] = 0;
	tmp = line;
	line = ft_strdup(line);
	free(tmp);
	return (0);
}

int		choose_return(char *buf, int rsize, int fd)
{
	if ((buf[0] && rsize == 0) || rsize == BUFFER_SIZE)
	{
		if (buf[BUFFER_SIZE - 1] == '\n')
		{
			rsize = read(fd, buf, BUFFER_SIZE);
			if (!rsize)
				return(0);
		}
		return (1);
	}
	if (rsize == -1)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static int	rsize;
	static char	buf[BUFFER_SIZE];

	if (fd < 0)
		return (-1);
	if (!(rsize))
		rsize = read(fd, buf, BUFFER_SIZE);
	*line = ft_strdup("");
	while (rsize > 0)
	{
		if (buf[0])
			*line = ft_strjoin(*line, buf);
		else
			rsize = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	take_rest(*line, buf);
	return (choose_return(buf, rsize, fd));
}
