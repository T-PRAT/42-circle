/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tprat <marvin@le-101.fr>                   +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 19:16:32 by tprat        #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 21:48:05 by tprat       ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		take_rest(char **line, char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while ((*line)[i] && (*line)[i] != '\n')
		i++;
	if (!((*line)[i]))
		return (0);
	(*line)[i] = 0;
	i++;
	while ((*line)[i])
		buf[j++] = (*line)[i++];
	buf[j] = 0;
	tmp = *line;
	*line = ft_strdup(*line);
	free(tmp);
	return (0);
}

int		choose_return(char *buf, int rsize)
{
	if (buf[0] || rsize != 0)
		return (1);
	if (rsize == -1)
		return (-1);
	return (0);
}

void	clear_buf(char *buf)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
		buf[i++] = 0;
}

int		get_next_line(int fd, char **line)
{
	static int	rsize;
	static char	buf[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	if (!(rsize))
		rsize = read(fd, buf, BUFFER_SIZE);
	*line = ft_strdup("");
	while (rsize > 0)
	{
		if (buf[0])
		{
			*line = ft_strjoin(line, buf);
			clear_buf(buf);
		}
		else
			rsize = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	take_rest(line, buf);
	return (choose_return(buf, rsize));
}
