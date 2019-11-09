/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:16:32 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:10:37 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc(char **line, char *buf, int s)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[0][i])
		i++;
	if (!(new = malloc(sizeof(char) * (i + 1 + s))))
		return (0);
	i = 0;
	while (line[0][i])
	{
		new[i] = line[0][i];
		i++;
	}
	while (buf[j] && buf[j] != '\n')
	{
		new[i + j] = buf[j];
		j++;
	}
	new[i + j] = 0;
	free(line);
	return (new);
}

int		take_line(char *buf, char **line)
{
	int i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (line[0])
	{
		if (!(*line = ft_realloc(line, buf, i)))
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

	while (take_line(buf, line) == 0)
	{
		if ((rsize = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
	}
	return (1);
}
