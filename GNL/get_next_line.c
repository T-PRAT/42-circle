/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:16:32 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 16:54:05 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		take_line(char *buf, char **line)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (line[0])
	{
		if (!(*line = ft_strjoin(line, buf)))
			return (-1);
	}
	else
	{
		if (!(*line = malloc(sizeof(char) * (i + 1))))
			return (-1);
		line[0][i] = 0;
		while (i--)
			line[0][i] = buf[i];
	}
	i = -1;
	while (buf[i++])
	{
		if (buf[i] == '\n')
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			rsize;
	char		buf[BUFFER_SIZE];
	int			t;
	char		rest[BUFFER_SIZE];

	if (rest[0])
		take_line(rest, line);
	if ((rsize = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	return (1);
}
